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
extern Request *fn_802137A4(int, int, int);
extern int fn_80212050(Request *, int);
extern int fn_80212E70(Request *, int, int, int, void *);

static inline int create_request(Request **out, int fd)
{
    int result = 0;
    Request *request;
    if (out == 0) {
        result = -4;
    } else {
        request = fn_802137A4(lbl_8059ECCC, 0x40, 0x20);
        *out = request;
        if (request == 0) {
            result = -0x16;
        } else {
            (*out)->callback = 0;
            (*out)->argument = 0;
            (*out)->state = 0;
            request->command = 7;
            request->fd = fd;
        }
    }
    return result;
}

int fn_80213090(int fd, int type, int inCount, int outCount, void *vectors)
{
    Request *request;
    int result = create_request(&request, fd);
    if (result == 0) {
        result = fn_80212E70(request, type, inCount, outCount, vectors);
        if (result == 0) {
            result = fn_80212050(request, 0);
        }
    }
    return result;
}