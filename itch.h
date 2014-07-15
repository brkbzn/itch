#define TESTS

typedef char* itch_msg;                  // message content only
typedef void (*itch_handler)(itch_msg); // message handler func type
typedef itch_handler itch_map[122];     // map of message name and func ptr

// emit looks up the data in itch_map and calls appropriate function
void itch_emit(itch_map* m, char* data);

// Handlers

#define MSG_SYSTEM_EVENT 'S'
void msg_system_event(itch_msg msg);
#define MSG_STOCK_DIRECTORY 'R'
void msg_stock_directory(itch_msg msg);
#define MSG_STOCK_TRADE 'H'
void msg_stock_trade(itch_msg msg);


// Utilities
long read_all(char* filename);  
void read_message(itch_map* m, long len, long offset);


// Tests
#ifdef TESTS
#define mu_assert(message, test) do { if (!(test)) return message;  } while (0)
#define mu_run_test(test) do { char *message = test(); tests_run++; if (message) return message; } while (0)

extern int tests_run;
#endif
