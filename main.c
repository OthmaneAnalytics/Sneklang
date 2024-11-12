#include "exercise.h"
#include <string.h>
#include <stdio.h>


int main() {
  packet_header_t header;
  header.tcp_header.src_port = 0xA3;
  header.tcp_header.dest_port = 0x5F;
  header.tcp_header.seq_num = 0x9D3C;
  printf("the raw packet header is %x\n", header.raw);  

  return 0;
}

