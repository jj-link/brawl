#pragma force_active on

typedef unsigned char u8;
typedef unsigned int u32;
typedef signed int s32;

struct Color {
    u8 r, g, b, a;
};

struct Colors {
    Color c[4];
    Color colA;
    Color colB;
};

namespace ms {
class CharWriter {
public:
    CharWriter();

    u32 w[8];      // 0x00-0x1C
    s32 state;     // 0x20
    float f24;     // 0x24
    float f28;     // 0x28
    float f2c;     // 0x2C
    float f30;     // 0x30
    float f34;     // 0x34
    s32 w38;       // 0x38
    s32 w3c;       // 0x3C
    u8 pad40[2];   // 0x40
    u8 opacity;    // 0x42
    u8 b43;        // 0x43
    float f44;     // 0x44
    s32 w48;       // 0x48 font
    u8 b4c;        // 0x4C
    u8 pad4d[3];   // 0x4D
    float f50;     // 0x50
    u8 b54;        // 0x54
    u8 b55;        // 0x55
    u8 pad56[2];   // 0x56
    float f58;     // 0x58
    float f5c;     // 0x5C
    u32 edge;      // 0x60
    s32 w64;       // 0x64
    float f68;     // 0x68
    u8 b6c;        // 0x6C
};
} // namespace ms

extern "C" u32 lbl_80497EC8[4];
extern "C" const float lbl_805A1A70;
extern "C" const float lbl_805A1A74;
extern "C" void SetColorMapping__Q22ms10CharWriterFQ34nw4r2ut5ColorQ34nw4r2ut5Color(ms::CharWriter* self, Color* a, Color* b);
extern "C" void SetTextColor__Q22ms10CharWriterFQ34nw4r2ut5Color(ms::CharWriter* self, Color* color);

namespace ms {
CharWriter::CharWriter() {
    s32 sp10;
    s32 spC;
    s32 sp8;

    w[0] = 0xFFFFFFFF;
    w[1] = 0xFFFFFFFF;
    w[2] = 0xFFFFFFFF;
    w[3] = 0xFFFFFFFF;
    w[4] = 0xFFFFFFFF;
    w[5] = 0xFFFFFFFF;
    w[6] = 0xFFFFFFFF;
    w[7] = 0xFFFFFFFF;
    opacity = 0xFF;
    b43 = 0;
    f44 = lbl_805A1A70;
    w48 = 0;
    b4c = 0;
    f50 = lbl_805A1A74;
    b54 = 0;
    b55 = 0;
    f58 = lbl_805A1A74;
    f5c = lbl_805A1A70;
    edge = 0xFF;
    w64 = 1;
    f68 = lbl_805A1A74;
    b6c = 0;

    lbl_80497EC8[0] = 0xFF;
    lbl_80497EC8[1] = 0;

    sp8 = 0;
    spC = -1;
    SetColorMapping__Q22ms10CharWriterFQ34nw4r2ut5ColorQ34nw4r2ut5Color(this, (Color*)&sp8, (Color*)&spC);

    state = 0;
    {
        Colors* cc = (Colors*)&w[2];
        cc->c[0] = cc->colA;
        cc->c[1] = (state != 1) ? cc->colA : cc->colB;
        cc->c[2] = (state != 2) ? cc->colA : cc->colB;
        cc->c[3] = (state == 0) ? cc->colA : cc->colB;
        cc->c[0].a = cc->c[0].a * opacity / 255;
        cc->c[1].a = cc->c[1].a * opacity / 255;
        cc->c[2].a = cc->c[2].a * opacity / 255;
        cc->c[3].a = cc->c[3].a * opacity / 255;
    }

    sp10 = -1;
    SetTextColor__Q22ms10CharWriterFQ34nw4r2ut5Color(this, (Color*)&sp10);

    f24 = lbl_805A1A74;
    f28 = lbl_805A1A74;
    f2c = lbl_805A1A70;
    f30 = lbl_805A1A70;
    f34 = lbl_805A1A70;
    w38 = 1;
    w3c = 1;
}
} // namespace ms
