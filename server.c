#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main(void) {
    int server_fd, client_fd;
    struct sockaddr_in address = {0};
    
    socklen_t addrlen = sizeof(address);
    
    char buffer[1024] = {0}; 
    
    const char *message = "Bienvenue sur mon serveur C ! \n";
    
    // 1. Créer une socket IPv4 utilisant TCP
    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd < 0) {
        perror("socket");
        return EXIT_FAILURE;
    }
    
    // 2. Configurer l'adresse : toutes les interfaces, port 4444
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(4444); // Note: ton commentaire disait 8080, mais le code dit 4444. 4444 c'est le port "hacker" classique !
    
    // 3. Associer la socket au port (Bind)
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0){
        perror("bind");
        close(server_fd);
        return EXIT_FAILURE;
    }
    
    // 4. Mettre le serveur en écoute (Listen)
    if (listen(server_fd, 3) < 0) {
        perror("listen");
        close(server_fd);
        return EXIT_FAILURE;
    }
    
    printf("Serveur en écoute sur le port 4444...\n");
    
    // 5. Attendre une connexion entrante (Accept)
    client_fd = accept(server_fd, (struct sockaddr *)&address, &addrlen);
    if (client_fd < 0) {
        perror("accept");
        close(server_fd);
        return EXIT_FAILURE;
    }
    
    printf("Un client s'est connecté !\n");
    
    // 6. Lire les données envoyées par le client (Read)
    // <--- CORRECTION : sizeof(buffer) - 1 pour laisser de la place au caractère de fin '\0'
    ssize_t bytes_read = read(client_fd, buffer, sizeof(buffer) - 1);
    
    if (bytes_read < 0) {
        perror("read");
    } else {
        buffer[bytes_read] = '\0'; // On termine la chaîne de caractères proprement
        printf("Message reçu du client : %s\n", buffer);
        
        // 7. Envoyer une réponse (Send)
        if (send(client_fd, message, strlen(message), 0) < 0) {
            perror("send");
        }
    }
    
    // 8. Fermer les descripteurs (Nettoyage)
    close(client_fd);
    close(server_fd);
    
    return EXIT_SUCCESS;
}
