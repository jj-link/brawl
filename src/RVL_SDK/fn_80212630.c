#pragma force_active on
typedef unsigned int u32;

typedef struct Request {
    int command;
    int result;
    int fd;
    void *buffer;
    u32 length;
    int unused[3];
    int callback;
    int userdata;
    int state;
} Request;

extern int lbl_8059ECCC;
extern Request *fn_802137A4(int, int, int);
extern void fn_801D76BC(void *, u32);
extern int fn_80212050(Request *, int);

static inline int create_request(Request **out, int fd, int callback, int userdata)
{
    int result = 0;
    Request *request;

    if (out == 0) {
        result = -4;
    } else {
        request = fn_802137A4(lbl_8059ECCC, 0x40, 0x20);
        *out = request;
        if (request == 0) {
            result = -22;
        } else {
            (*out)->callback = callback;
            (*out)->userdata = userdata;
            (*out)->state = 0;
            request->command = 3;
            request->fd = fd;
        }
    }
    return result;
}

static inline int set_buffer(Request *request, void *buffer, u32 length)
{
    int result = 0;

    if (request == 0) {
        result = -4;
    } else {
        fn_801D76BC(buffer, length);
        request->buffer = buffer ? (void *)((u32)buffer + 0x80000000) : 0;
        request->length = length;
    }
    return result;
}

int fn_80212630(int fd, void *buffer, u32 length, int callback, int userdata)
{
    Request *request;
    int result = create_request(&request, fd, callback, userdata);

    if (result == 0) {
        result = set_buffer(request, buffer, length);
        if (result == 0) {
            result = fn_80212050(request, callback);
        }
    }
    return result;
}
