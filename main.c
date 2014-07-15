#include <stdlib.h>
#include <stdio.h>

#include "itch.h"

#ifdef TESTS
// run against test data
int main() {

    itch_map m = {};
    m[MSG_STOCK_DIRECTORY] = msg_stock_directory;
    m[MSG_SYSTEM_EVENT] = msg_system_event;
    m[MSG_STOCK_TRADE] = msg_stock_trade;

    long len = read_all("test_data");
    read_message(&m, len, 0);

    return 0;
}
#endif
