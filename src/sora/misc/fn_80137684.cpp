#pragma force_active on
extern "C" {
struct Flags {
    unsigned char pad[0x6f];
    unsigned char f7 : 1;
    unsigned char f6 : 1;
    unsigned char f5 : 1;
    unsigned char f4 : 1;
    unsigned char rest : 4;
};

void fn_80137684(struct Flags* p, unsigned long a, unsigned long b, unsigned long c, unsigned long d) {
    p->f7 = a;
    p->f6 = b;
    p->f5 = c;
    p->f4 = d;
}
}
