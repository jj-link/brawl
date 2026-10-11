typedef unsigned long u32;

struct TRKMessageBuffer {
    u32 x0;
    u32 x4;
    u32 end;
    u32 cursor;
    unsigned char data[0x880];
};

extern void* fn_80402EF0(void);
extern void fn_80402EE4(void* request);
/* TRK calls this entry point with its fixed one-string reporting ABI. */
extern void OSReport(const char* message);
extern int fn_80401868(struct TRKMessageBuffer* buffer, u32 position);
extern int fn_80402E5C(struct TRKMessageBuffer* buffer);
extern int fn_80402DC0(struct TRKMessageBuffer* buffer);
extern int fn_80402D44(struct TRKMessageBuffer* buffer);
extern int fn_80402CC8(struct TRKMessageBuffer* buffer);
extern int fn_80402CC0(void* request);
extern int fn_80402CB8(void* request);
extern int fn_80402A70(struct TRKMessageBuffer* buffer);
extern int fn_80402854(struct TRKMessageBuffer* buffer);
extern int fn_80402630(struct TRKMessageBuffer* buffer);
extern int fn_80402374(struct TRKMessageBuffer* buffer);
extern int fn_80402290(struct TRKMessageBuffer* buffer);
extern int fn_80401FBC(struct TRKMessageBuffer* buffer);
extern int fn_80401EF0(struct TRKMessageBuffer* buffer);
extern int fn_80401E24(struct TRKMessageBuffer* buffer);

static inline int TRKReportChar(signed char character) {
    char message[2];
    void* saved_request;

    saved_request = fn_80402EF0();
    message[0] = character;
    message[1] = 0;
    fn_80402EE4(0);
    OSReport(message);
    fn_80402EE4(saved_request);
    return 0;
}

int fn_80401C54(const char* text) {
    signed char character;
    int status = 0;

    while (status == 0 && (character = (signed char)*text++) != 0) {
        status = TRKReportChar(character);
    }
    return status;
}

int TRKDispatchMessage(struct TRKMessageBuffer* buffer) {
    int status = 0x500;

    fn_80401868(buffer, 0);
    switch (buffer->data[4]) {
    case 1:
        status = fn_80402E5C(buffer);
        break;
    case 2:
        status = fn_80402DC0(buffer);
        break;
    case 3:
        status = fn_80402D44(buffer);
        break;
    case 7:
        status = fn_80402CC8(buffer);
        break;
    case 4:
        status = fn_80402CC0(buffer);
        break;
    case 5:
        status = fn_80402CB8(buffer);
        break;
    case 16:
        status = fn_80402A70(buffer);
        break;
    case 17:
        status = fn_80402854(buffer);
        break;
    case 18:
        status = fn_80402630(buffer);
        break;
    case 19:
        status = fn_80402374(buffer);
        break;
    case 24:
        status = fn_80402290(buffer);
        break;
    case 25:
        status = fn_80401FBC(buffer);
        break;
    case 26:
        status = fn_80401EF0(buffer);
        break;
    case 23:
        status = fn_80401E24(buffer);
        break;
    case 0:
    case 6:
    case 8:
    case 9:
    case 10:
    case 11:
    case 12:
    case 13:
    case 14:
    case 15:
    case 20:
    case 21:
    case 22:
    default:
        break;
    }
    return status;
}
