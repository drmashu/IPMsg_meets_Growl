/*
 *  IP Messenger Grwoling part 
 *
 *  Copyright (c) 2009 snaka<snaka.gml@gmail.com>
 */

#include "ipmsg.h"

void GNTP_SendAndRecieve(char *message) {
  struct sockaddr_in server;
  SOCKET  sock;
  char buf[MAX_SOCKBUF];
 
  // Create socket
  sock = ::Tsocket(AF_INET, SOCK_STREAM, 0);
 
  // Configure socket
  server.sin_family = AF_INET;
  server.sin_port = ::Thtons(23053);
  server.sin_addr.S_un.S_addr = ::Tinet_addr("127.0.0.1");
 
  // Connect to server
  ::Tconnect(sock, (struct sockaddr *)&server, sizeof(server));
 
  // Send data (Register)
  memset(buf, 0, sizeof(buf));
  _snprintf_s(buf, sizeof(buf), sizeof(buf)-1, message);
  ::Tsend(sock, buf, sizeof(buf), 0);
  
  // Recieve data from server
  memset(buf, 0, sizeof(buf));
  int n = ::Trecv(sock, buf, sizeof(buf), 0);
  
  ::Tclosesocket(sock);
}
