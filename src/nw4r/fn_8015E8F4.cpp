#pragma force_active on

typedef unsigned char u8;
typedef unsigned int u32;
typedef signed int s32;

struct Color { u8 r, g, b, a; };

struct Colors {
    Color c[4];
    Color colA;
    Color colB;
};

struct S {
    u32 w[8];         // 0x00-0x1C
    s32 state;        // 0x20
    float f24;        // 0x24
    float f28;        // 0x28
    float f2c;        // 0x2C
    float f30;        // 0x30
    float f34;        // 0x34
    s32 w38;          // 0x38
    s32 w3c;          // 0x3C
    u8 pad40[2];      // 0x40
    u8 opacity;       // 0x42
    u8 b43;           // 0x43
    float f44;        // 0x44
    s32 w48;          // 0x48
};

extern "C" void fn_8015EB14(unsigned char* dst, const unsigned char* src1, const unsigned char* src2);
extern "C" void fn_8015EB58(S* arg0, void* color);
extern "C" u32 lbl_8049EDA0[4];
extern "C" const float lbl_805A2BB8;
extern "C" const float lbl_805A2BBC;

extern "C" S* fn_8015E8F4(S* arg0) {
    s32 sp10;
    s32 spC;
    s32 sp8;

    arg0->w[0] = -1;
    arg0->w[1] = -1;
    arg0->w[2] = -1;
    arg0->w[3] = -1;
    arg0->w[4] = -1;
    arg0->w[5] = -1;
    arg0->w[6] = -1;
    arg0->w[7] = -1;
    arg0->opacity = 0xFF;
    arg0->b43 = 0;
    arg0->f44 = lbl_805A2BB8;
    arg0->w48 = 0;
    lbl_8049EDA0[0] = 0xFF;
    lbl_8049EDA0[1] = 0;

    sp8 = 0;
    spC = -1;
    fn_8015EB14((unsigned char*)arg0, (const unsigned char*)&sp8, (const unsigned char*)&spC);

    arg0->state = 0;
    {
        Colors* cc = (Colors*)&arg0->w[2];
        cc->c[0] = cc->colA;
        cc->c[1] = (arg0->state != 1) ? cc->colA : cc->colB;
        cc->c[2] = (arg0->state != 2) ? cc->colA : cc->colB;
        cc->c[3] = (arg0->state == 0) ? cc->colA : cc->colB;
        cc->c[0].a = cc->c[0].a * arg0->opacity / 255;
        cc->c[1].a = cc->c[1].a * arg0->opacity / 255;
        cc->c[2].a = cc->c[2].a * arg0->opacity / 255;
        cc->c[3].a = cc->c[3].a * arg0->opacity / 255;
    }

    sp10 = -1;
    fn_8015EB58(arg0, &sp10);

    arg0->f24 = lbl_805A2BBC;
    arg0->f28 = lbl_805A2BBC;
    arg0->f2c = lbl_805A2BB8;
    arg0->f30 = lbl_805A2BB8;
    arg0->f34 = lbl_805A2BB8;
    arg0->w38 = 1;
    arg0->w3c = 1;
    return arg0;
}
