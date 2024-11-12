#include "http.h"
#include <stdio.h>

int main(void) {
  HttpErrorCode code = HTTP_UNAUTHORIZED;
  BigNumbers b = BIG;
  printf("%s \n", http_to_str(code));
  printf("the size of a big number is %zu \n",sizeof(b));
  printf("the size of http error code is %zu \n",sizeof(code));
}
