#pragma force_active on
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Work {
    int state;
    unsigned char pad[0x6B0];
    int socket;
} Work;

extern u16 SOHtoNs(u16);
extern void *memcpy(void *, const void *, unsigned long);
extern void fn_8038A904(Work *, int, int, int, int);
extern int fn_8038A574(Work *, const void *, int);
extern int send(int, const void *, int, int);

int fn_8038CFA4(Work *self, u32 arg1, u16 arg2, const void *data, int length)
{
    unsigned char header[9];
    u16 size;
    int result;

    if (self->state == 1) {
        fn_8038A904(self, 0, 0, 2, 0);
    }
    if (self->state == 1) {
        return 3;
    }

    size = SOHtoNs((u16)(length + 9));
    memcpy(header, &size, 2);
    header[2] = 2;
    memcpy(header + 3, &arg1, 4);
    memcpy(header + 7, &arg2, 2);

    result = fn_8038A574(self, header, 9);
    if (result != 0) {
        return result;
    }

    result = send(self->socket, data, length, 0);
    {
        int status = 0;
        if (result < 0) {
            status = 3;
        }
        return status;
    }
}
