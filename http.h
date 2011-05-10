#ifndef http_h
#define http_h

typedef struct http_context_s http_context;
typedef struct http_session_s http_session;
typedef struct http_request_s http_request;

/*
 * A Context is bound to a collection of sessions and
 * ongoing requests. Each thread in a process should have its
 * own Context to avoid deadlocks and conflicts.
 */
http_context* http_context_create();
void http_context_release(http_context* ctx);

/*
 * A session represents an active communication line to a server.
 * One or more network sockets may be open to the server to
 * fulfill requests. Pipelining will be used if supported by server.
 */
http_session* http_session_open(http_context* ctx, const char* host, int port);
void http_session_close(http_session* session);

http_request* http_request_create(http_session* session, const char* path, http_method method);
http_request* http_request_get(http_session* session, const char* path);
http_request* http_request_post(http_session* session, const char* path);

#endif
