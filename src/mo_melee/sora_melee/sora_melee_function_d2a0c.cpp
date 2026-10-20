#pragma force_active on
typedef struct {
    unsigned char flags;
    unsigned char pad1;
    unsigned short a;
    short b;
    int c;
    unsigned short d;
    short e;
} fnS27D2A0C;

extern "C" void fn_27_D2A0C(fnS27D2A0C* p) {
    p->flags |= 0x80;
    p->a = 0;
    p->b = -1;
    p->c = -1;
    p->d = 0;
    p->e = -1;
}
