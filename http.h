#ifndef http_h
#define http_h

#include "stddef.h"

typedef struct http_stream_s http_stream;
typedef struct http_session_s http_session;
typedef struct http_message_s http_message;

typedef int (*http_stream_cb)(http_stream* stream, void* context);

enum http_error_codes {
  HTTP_ENOTIMPL         // Not yet implemented.
};

// Streams provide an interface for writing data to the socket
// bound to a session. They are responsible for handling any
// encoding/decoding of the data. Data will be written or read from
// buffers supplied and returning number of bytes actually transferred.
// Note: these methods may or may not block depending on the
// underlying socket's mode.
size_t http_stream_read(char* buffer, size_t size);
size_t http_stream_write(const char* buffer, size_t size);

// A session represents a connection between a client and the server.
// Create a socket connected to the server or accept incoming client
// from listening socket. Initialize a new HTTP session using this socket.
// Closing the session also closes the underlying socket.
http_session* http_session_init(int sockfd);
void http_session_close(http_session* session);

// Parsing of messages arriving from a session.
// Clients will parse responses while servers parse requests.
http_message* http_session_parse_request(http_session* session);
http_message* http_session_parse_response(http_session* session);

// Compose a new message for sending with a session.
// Clients will compose requests while servers compose responses.
http_message* http_request(const char* method, const char* uri);
http_message* http_response(int status_code, const char* reason_phrase);

// Append a new header to the message if a field with
// this name does not yet exist. If it already exists then
// the new value will be appended follow RFC2616 4.2 guidelines.
void http_message_set_header(http_message* msg, const char* name, const char* value);

// Set a stream callback for reading or writing the message body.
// A parsed (incoming) message will read while a composed (outgoing)
// message will be writing.
void http_message_set_body_cb(http_message* msg, http_stream_cb cb, void* context);

// Send a fully composed message with a session.
int http_session_send_message(http_session* session, const http_message* msg);

#endif
