#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;

extern const float lbl_805A2210;
extern const float lbl_805A2214;
extern const float lbl_805A2218;
extern const float lbl_805A221C;
extern const float lbl_805A2220;
extern const float lbl_805A2224;
extern const float lbl_805A2228;

class MuMsg {
public:
    struct WindowSetting {
        u32 bit0 : 1;
        u32 bit1 : 6;
        u32 bit7 : 3;
        u32 rest : 22;
        float f04, f08, f0C, f10;
        u8 b14, b15, b16, b17, b18, b19, b1A, b1B;
        float f1C, f20, f24, f28, f2C, f30, f34, f38;
        float f3C, f40, f44;
    };

    void initWindowSetting(WindowSetting*);
};

void MuMsg::initWindowSetting(WindowSetting* p)
{
    float d, c, g, f, e, b, a;

    p->bit0 = 0;
    p->bit1 = 0;

    a = lbl_805A2210;
    b = lbl_805A2214;
    c = lbl_805A2224;
    d = lbl_805A2228;
    e = lbl_805A2218;
    f = lbl_805A221C;
    g = lbl_805A2220;

    p->f04 = a;
    p->f08 = a;
    p->f0C = b;
    p->f10 = b;
    p->b14 = 255;
    p->b15 = 255;
    p->b16 = 255;
    p->b17 = 255;

    p->bit7 = 0;
    p->f1C = e;
    p->f20 = f;
    p->b18 = 0;
    p->b19 = 0;
    p->b1A = 0;
    p->b1B = 255;
    p->f24 = a;
    p->f28 = g;
    p->f2C = c;
    p->f30 = d;
    p->f34 = d;
    p->f38 = c;
    p->f3C = a;
    p->f40 = a;
    p->f44 = a;
}
