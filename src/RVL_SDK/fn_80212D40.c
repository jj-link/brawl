#pragma force_active on
typedef unsigned int u32;
typedef struct Request {
    int command;
    int result;
    int fd;
    int ioctl;
    u32 input;
    u32 input_length;
    u32 output;
    u32 output_length;
    void *callback;
    void *argument;
    int state;
} Request;
extern int lbl_8059ECCC;
extern Request *fn_802137A4(int, int, int);
extern int fn_80212050(Request *, int);
extern void DCFlushRange(void *, u32);
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
            result = -22;
        } else {
            (*out)->callback = 0;
            (*out)->argument = 0;
            (*out)->state = 0;
            request->command = 6;
            request->fd = fd;
        }
    }
    return result;
}
static inline int set_ioctl(Request *request, int ioctl, void *input, u32 input_length, void *output, u32 output_length)
{
    int result = 0;
    if (request == 0) {
        result = -4;
    } else {
        request->ioctl = ioctl;
        request->output = output ? (u32)output + 0x80000000 : 0;
        request->output_length = output_length;
        request->input = input ? (u32)input + 0x80000000 : 0;
        request->input_length = input_length;
        DCFlushRange(input, input_length);
        DCFlushRange(output, output_length);
    }
    return result;
}
int fn_80212D40(int fd, int ioctl, void *input, u32 input_length, void *output, u32 output_length)
{
    Request *request;
    int result = create_request(&request, fd);
    if (result == 0) {
        result = set_ioctl(request, ioctl, input, input_length, output, output_length);
        if (result == 0) {
            result = fn_80212050(request, 0);
        }
    }
    return result;
}