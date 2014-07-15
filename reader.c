#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>

#include "itch.h"

static char* data;

long read_all(char* filename) {

    FILE *f = fopen(filename, "rb");

    if (errno != 0) {
        exit(errno);
    }

    fseek(f, 0, SEEK_END);
    long len = ftell(f);
    rewind(f);

    data = realloc(data, len + 1);
    fread(data, len, 1, f);
    fclose(f);
    
    return len;
}

void read_message(itch_map* m, long len, long offset) {

    // done reading
    if (offset >= len) {
        free(data);
        return;
    }

    if (data[offset] == 0x00) {
        offset++;
        read_message(m, len, offset);
    }

    int msg_len = data[offset];
    if (msg_len < 1)  {
           printf("got bad message len, %i\n", data[offset]);
    }
    char* msg = malloc(msg_len);
    for (int i = 0; i < msg_len; i++) {
        msg[i] = data[offset+i];
    }

    itch_emit(m, msg);
    free(msg);

    offset += msg_len + 1;;

    read_message(m, len, offset);
}
