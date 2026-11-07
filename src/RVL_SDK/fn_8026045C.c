#pragma force_active on
typedef struct {
    void *ptr;
    int format;
    unsigned short width, height;
    unsigned char a, pad;
    unsigned short b;
    unsigned char c, pad2[3];
    int result;
    int arg;
    char reserved[0x80];
    unsigned int size;
} Params;
typedef struct {
    char pad[0x10];
    int out1;
    int out2;
    char rest[0x6e4];
} Work;
extern int fn_8026CAE0(Work *, int, Params *);
extern int fn_8026B3D8(Work *, void *, int, Params *);
extern int fn_8026B544(Work *, int, int);
int TMCCJPEGEncGetQFactor(void *arg0, int arg1, int arg2, int arg3, int arg4, int arg5, int *arg6, int *arg7) {
    Work work;
    Params p;
    int r, count;
    *arg6 = 0;
    *arg7 = 0;
    if (arg2 > 0xffff || arg2 <= 0 || arg3 > 0xffff || arg3 <= 0)
        r = -1;
    else if (arg4 != 4 && arg4 != 6)
        r = -4;
    else
        r = 0;
    if (r < 0) return r;
    p.width = arg2;
    p.ptr = arg0;
    p.height = arg3;
    p.a = 2;
    p.c = 1;
    p.result = 0;
    p.b = 0;
    p.format = arg4;
    p.size = 0;
    p.arg = arg5;
    r = fn_8026CAE0(&work, arg1, &p);
    if (r < 0) return r;
    p.result = r;
    p.ptr = arg0;
    p.size = 0x400;
    if (p.size >= 0x5b4) return -0x90;
    count = fn_8026B3D8(&work, (char *)arg0 + 0x164c, arg1, &p);
    if (count < 0) return count;
    do {
        r = fn_8026B544(&work, count, arg1);
        if (r < 0) {
            if (r != -3) return r;
            break;
        } else if (r <= 0) {
            break;
        }
    } while (1);
    *arg7 = work.out2;
    *arg6 = work.out1;
    return 0;
}