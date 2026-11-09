#include <revolution/OS/OSCache.h>
#pragma force_active on
typedef struct Request {
    int command;
    int result;
    int fd;
    int type;
    unsigned int in;
    int inSize;
    unsigned int out;
    int outSize;
    void *callback;
    void *argument;
    int state;
} Request;
extern int lbl_8059ECCC;
extern Request *fn_802137A4(int, int, int);
extern int fn_80212050(Request *, void *);
static inline int create_request(Request **out, int fd, void *callback, void *argument)
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
            (*out)->argument = argument;
            (*out)->state = 0;
            request->command = 6;
            request->fd = fd;
        }
    }
    return result;
}
static inline int set_ioctl(Request *request, int type, void *in, int inSize, void *out, int outSize)
{
    int result = 0;
    if (request == 0) {
        result = -4;
    } else {
        request->type = type;
        request->out = out ? (unsigned int)out + 0x80000000 : 0;
        request->outSize = outSize;
        request->in = in ? (unsigned int)in + 0x80000000 : 0;
        request->inSize = inSize;
        DCFlushRange(in, inSize);
        DCFlushRange(out, outSize);
    }
    return result;
}
int fn_80212C08(int fd, int type, void *in, int inSize, void *out, int outSize, void *callback, void *argument)
{
    Request *request;
    int result = create_request(&request, fd, callback, argument);
    if (result == 0) {
        result = set_ioctl(request, type, in, inSize, out, outSize);
        if (result == 0) {
            result = fn_80212050(request, callback);
        }
    }
    return result;
}