#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;
typedef float f32;

struct Bits8 {
    u8 b0 : 1;
    u8 b1 : 1;
    u8 b2 : 1;
    u8 b3 : 1;
    u8 b4 : 1;
    u8 b5 : 1;
    u8 b6 : 1;
    u8 b7 : 1;
};

extern f32 lbl_57_rodata_118[];

extern "C" {
void fn_57_43F0(void* self) {
    u8* s = (u8*)self;
    f32* tbl = lbl_57_rodata_118;
    u8* b;
    f32* a = *(f32**)(s + 0x158);
    u8* c;
    u8* d;
    u8* e;
    Bits8* p;

    if (a == 0) return;
    b = *(u8**)(s + 0x15C);
    if (b == 0) return;
    c = *(u8**)(s + 0x184);
    if (c == 0) return;
    if (*(void**)(s + 0x188) == 0) return;

    switch (*b) {
    case 2:
        if (*a >= tbl[22]) {
            p = (Bits8*)(c + 0x54);
            p->b3 = 1;
            p->b1 = p->b3;
            d = *(u8**)(s + 0x188);
            p = (Bits8*)(d + 0x54);
            p->b3 = 1;
            p->b1 = p->b3;
            e = *(u8**)(s + 0x184);
            p = (Bits8*)(e + 0x55);
            p->b4 = 0;
        } else {
            p = (Bits8*)(c + 0x54);
            p->b0 = 0;
            p->b3 = p->b0;
            p->b1 = p->b3;
            d = *(u8**)(s + 0x188);
            p = (Bits8*)(d + 0x54);
            p->b0 = 0;
            p->b3 = p->b0;
            p->b1 = p->b3;
        }
        break;
    case 3:
        p = (Bits8*)(c + 0x54);
        p->b3 = 1;
        p->b1 = p->b3;
        d = *(u8**)(s + 0x188);
        p = (Bits8*)(d + 0x54);
        p->b3 = 1;
        p->b1 = p->b3;
        break;
    case 4:
        if (*a >= tbl[23]) {
            p = (Bits8*)(c + 0x54);
            p->b0 = 0;
            p->b3 = p->b0;
            p->b1 = p->b3;
            d = *(u8**)(s + 0x188);
            p = (Bits8*)(d + 0x54);
            p->b0 = 0;
            p->b3 = p->b0;
            p->b1 = p->b3;
        } else if (*a >= tbl[24]) {
            p = (Bits8*)(c + 0x54);
            p->b3 = 1;
            p->b1 = p->b3;
            d = *(u8**)(s + 0x188);
            p = (Bits8*)(d + 0x54);
            p->b0 = 0;
            p->b3 = p->b0;
            p->b1 = p->b3;
            e = *(u8**)(s + 0x184);
            p = (Bits8*)(e + 0x55);
            p->b4 = 1;
        } else {
            p = (Bits8*)(c + 0x54);
            p->b3 = 1;
            p->b1 = p->b3;
            d = *(u8**)(s + 0x188);
            p = (Bits8*)(d + 0x54);
            p->b3 = 1;
            p->b1 = p->b3;
        }
        break;
    }
}
}
