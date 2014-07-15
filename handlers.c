#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "itch.h"

typedef int t_nano;


typedef struct {
    char len;
    char msg;
    int time;
    char code;
} t_system_event;

void msg_system_event(itch_msg msg) {

    t_system_event ev;

    memcpy(&ev, msg, msg[0]);

    printf("len: %i, msg %c\ttime %i\tcode %c\n", 
            ev.len,
            ev.msg,
            ev.time,
            ev.code);
}

void msg_stock_directory(itch_msg msg) {

}

typedef struct {
    char len;
    char msg;
    int time;
    char stock[8];
    char status;
    char reserved;
    char reason[4];

} t_stock_trade;

void msg_stock_trade(itch_msg msg) {

    t_stock_trade ev;

    int msg_len = msg[0];

    memcpy(&ev, msg, msg_len);

    printf("len: %i, msg %c\ttime %i\tstock %s\tstatus %c\treserved %c\treason %s\n", 
            ev.len,
            ev.msg, 
            ev.time,
            ev.stock,
            ev.status,
            ev.reserved,
            ev.reason);
}
