#pragma force_active on
typedef struct {
    unsigned int w0;
    struct {
        unsigned int hi : 8;
        unsigned int lo : 24;
    } w4;
    short h8;
} S;

void fn_801F3004(S *p, unsigned int arg1, int arg2, short arg3) {
    union {
        unsigned int w;
        struct {
            unsigned int a : 20;
            unsigned int b : 2;
            unsigned int c : 10;
        } f;
    } u;
    u.w = 0;
    p->w4.lo = arg1 >> 5;
    u.f.b = arg2;
    p->h8 = arg3;
    p->w4.hi = 0x64;
    p->w0 = u.w;
}
