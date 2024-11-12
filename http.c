#include "http.h"

char *http_to_str(HttpErrorCode code) {
  switch(code){
    case 400:
      return "400 Bad Request";
    case 401:
      return "401 Unauthorized";
    case 418:
      return "418 I AM A TEAPOT";
    case 500:
      return "500 Intenal Server Error";
    default:
      return "Unknown HTTP status code";
  }
}

