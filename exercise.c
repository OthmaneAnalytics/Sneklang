#include <stdlib.h>
#include <string.h>

void swap(void *vp1, void *vp2, size_t size) {
  void* vp3 = malloc(size);
  if(vp3 == NULL){
    return;
  }
  memcpy(vp3,vp1,size);
  memcpy(vp1,vp2,size);
  memcpy(vp2,vp3,size);
  free(vp3);
}

