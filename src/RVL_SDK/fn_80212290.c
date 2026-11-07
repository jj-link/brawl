#pragma force_active on
typedef unsigned int u32;

typedef struct Request {
    int command;
    int result;
    int fd;
    u32 path;
    int flags;
    int unused[3];
    int callback;
    int userdata;
    int state;
} Request;

extern int lbl_8059ECCC;
extern Request *fn_802137A4(int, int, int);
extern int fn_80212050(Request *, int);
extern void DCFlushRange(void *, u32);

static inline int create_request(Request **out, int callback, int userdata)
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
            request->command = 1;
            request->fd = 0;
        }
    }
    return result;
}

int fn_80212290(unsigned char *path, int flags, int callback, int userdata)
{
    Request *request;
    int result = create_request(&request, callback, userdata);

    if (result == 0) {
        Request *r = request;
        result = 0;
        if (r == 0) {
            result = -4;
        } else {
            unsigned char *p = path;
            int n = 0x40;
            for (; *p != 0 && n-- != 0; p++) {
            }
            DCFlushRange(path, (u32)(p - path) + 1);
            r->path = (u32)path + 0x80000000;
            r->flags = flags;
        }
        if (result == 0) {
            result = fn_80212050(request, callback);
        }
    }
    return result;
}
