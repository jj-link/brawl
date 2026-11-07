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
static int create_request(Request **out, int fd, int callback, int argument)
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
            (*out)->userdata = argument;
            (*out)->state = 0;
            request->command = 2;
            request->fd = fd;
        }
    }
    return result;
}
int fn_802124C8(int fd, int callback, int argument)
{
    Request *request;
    int result = create_request(&request, fd, callback, argument);
    if (result == 0) {
        result = fn_80212050(request, callback);
    }
    return result;
}