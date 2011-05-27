#include "http.h"

struct http_message_s {
  unsigned short http_version_major, http_version_minor;
  enum http_message_type type;
};

int http_message_get_type(http_message* msg) {
  return msg->type;
}

