#pragma force_active on

typedef unsigned int u32;

typedef struct Request {
    int command;
    int result;
    int fd;
    u32 buffer;
    u32 length;
    int unknown14;
    int unknown18;
    int unknown1c;
    void *callback;
    void *argument;
    int state;
    int unknown2c[5];
} Request;

extern int lbl_8059ECCC;
extern void *fn_802137A4(int, int, int);
extern int fn_80212050(Request *, void *);
extern void DCFlushRange(void *, u32);

static int create_request(Request **out, int fd, void *callback, void *argument)
{
    int result = 0;
    Request *request;

    if (out == 0) {
        result = -4;
    } else {
        request = (Request *)fn_802137A4(lbl_8059ECCC, 0x40, 0x20);
        *out = request;
        if (request == 0) {
            result = -22;
        } else {
            (*out)->callback = callback;
            (*out)->argument = argument;
            (*out)->state = 0;
            request->command = 4;
            request->fd = fd;
        }
    }
    return result;
}

static int set_buffer(Request *request, void *buffer, u32 length)
{
    int result = 0;

    if (request == 0) {
        result = -4;
    } else {
        request->buffer = buffer ? (u32)buffer + 0x80000000 : 0;
        request->length = length;
        DCFlushRange(buffer, length);
    }
    return result;
}

int fn_80212938(int fd, void *buffer, u32 length)
{
    Request *request;
    int result = create_request(&request, fd, 0, 0);

    if (result == 0) {
        result = set_buffer(request, buffer, length);
        if (result == 0) {
            result = fn_80212050(request, 0);
        }
    }
    return result;
}
