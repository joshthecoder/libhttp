#include "http.h"

#include <stdlib.h>

#ifdef PLATFORM_POSIX
#include <unistd.h>
#endif

struct http_session_s {
  int sockfd;
};

http_session* http_session_init(int sockfd) {
  http_session* session = malloc(sizeof(http_session));
  if (!session) return NULL;

  session->sockfd = sockfd;

  return session;
}

void http_session_close(http_session* session) {
  close(session->sockfd);
  free(session);
}

http_message* http_session_parse_request(http_session* session) {
  /* TODO: implement */
  return NULL;
}

http_message* http_session_parse_response(http_session* session) {
  /* TODO: implement */
  return NULL;
}

int http_session_send_message(http_session* session, const http_message* msg) {
  /* TODO: implement */
  return HTTP_ENOTIMPL;
}

