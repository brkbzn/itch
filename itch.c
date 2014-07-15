#include <stdlib.h>
#include <stdio.h>

#include "itch.h"

void itch_add_handler(itch_map i_map, char c, itch_handler i_handler) {

    i_map[(int)c] = i_handler;
}

void itch_emit(itch_map* m, char* msg) {

    itch_handler handler = (*m)[(int)msg[1]];
    //printf("Got event %c with len %i\n", data[1], data[0]);
    if (handler) {
        handler(msg);
    }

}
