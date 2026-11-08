#pragma force_active on
typedef struct Packet {
    unsigned short pad0, field2, field4;
    unsigned char pad6[14];
    unsigned char field14, field15, field16, field17;
} Packet;
extern void *fn_8022EFF8(int);
extern void fn_80254D68(int, int, void *);
void fn_80255210(int arg0, int arg1, int arg2, int arg3) {
    Packet *p;
    unsigned char f14;
    p = fn_8022EFF8(2);
    if (p != 0) {
        p->field4 = 12;
        f14 = (unsigned char)((((-arg2 | arg2) >> 31) & 2) | 0x51);
        p->field14 = f14;
        p->field15 = 5;
        p->field16 = (unsigned char)(((arg1 << 2) & 0x3FC) | 3);
        p->field17 = (unsigned char)(arg3 | 1);
        p->field2 = 4;
        fn_80254D68(arg0, 0, p);
    }
}