#pragma force_active on
typedef struct Request {
    int command;
    int result;
    int fd;
    int unused[5];
    int callback;
    int userdata;
    int state;
} Request;

extern int lbl_8059ECCC;
extern Request *fn_802137A4(int, int, int);
extern int fn_80212E70(Request *, int, int, int, void *);
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
            request->command = 7;
            request->fd = fd;
        }
    }
    return result;
}

int fn_80212FAC(int fd, int type, int inCount, int outCount, void *vectors, int callback, int userdata)
{
    Request *request;
    int result = create_request(&request, fd, callback, userdata);

    if (result == 0) {
        result = fn_80212E70(request, type, inCount, outCount, vectors);
        if (result == 0) {
            result = fn_80212050(request, callback);
        }
    }
    return result;
}