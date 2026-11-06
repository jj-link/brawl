#pragma force_active on

typedef struct Request {
    int command;
    int result;
    int fd;
    int unknown0c;
    int unknown10;
    int unknown14;
    int unknown18;
    int unknown1c;
    int callback;
    int userdata;
    int state;
} Request;

extern int lbl_8059ECCC;
extern Request *fn_802137A4(int, int, int);
extern int fn_80212050(Request *, int);

static inline int create_request(Request **out, int fd0, int fd1, int fd2)
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
            (*out)->callback = 0;
            (*out)->userdata = 0;
            (*out)->state = 0;
            request->command = 5;
            request->fd = fd0;
        }
    }
    if (result == 0) {
        result = 0;
        request = *out;
        if (request == 0) {
            result = -4;
        } else {
            request->unknown0c = fd1;
            request->unknown10 = fd2;
        }
        if (result == 0) {
            result = fn_80212050(*out, 0);
        }
    }
    return result;
}

int fn_80212B20(int arg0, int arg1, int arg2)
{
    Request *request;
    return create_request(&request, arg0, arg1, arg2);
}
