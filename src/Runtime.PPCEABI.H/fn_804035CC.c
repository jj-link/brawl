typedef unsigned long u32;
typedef unsigned short u16;

struct TRKMessageBuffer {
    u32 x0;
    u32 x4;
    u32 end;
    u32 cursor;
    unsigned char data[0x880];
};

extern int fn_80401968(int* out_index, struct TRKMessageBuffer** out_buffer);
extern void fn_804018D8(int index);
extern int fn_80403214(struct TRKMessageBuffer* request, int* reply_id,
                       int minimum_reply_size, u32 retries, int use_timeout);
extern int fn_80403E8C(struct TRKMessageBuffer* buffer);
extern int fn_80403F10(struct TRKMessageBuffer* buffer);

int fn_804035CC(int command) {
    int reply_id;
    int request_id;
    struct TRKMessageBuffer* request;
    int result;

    result = fn_80401968(&request_id, &request);
    if (result == 0) {
        if (result == 0) {
            if (command == 0x90) {
                fn_80403F10(request);
            } else {
                fn_80403E8C(request);
            }
        }
        result = fn_80403214(request, &reply_id, 2, 3, 1);
        if (result == 0) {
            fn_804018D8(reply_id);
        }
        fn_804018D8(request_id);
    }
    return result;
}
