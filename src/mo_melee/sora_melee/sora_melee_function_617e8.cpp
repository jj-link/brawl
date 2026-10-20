#pragma force_active on
extern const float lbl_27_rodata_8B0;
extern const float lbl_27_rodata_8B4;

struct Vec2 {
    float x, y;

    Vec2(float a, float b) : x(a), y(b) {}
};

struct Data {
    unsigned char pad[0xBC];
    float bc;
    int c0;
    int c4;
    float c8, cc, d0, d4, d8;
    int dc, e0;
    float e4;
    int e8;
    float ec;
    unsigned char padF0[8];
    int f8;
    unsigned char padFC[5];
    unsigned char flag : 1;
    unsigned char keep : 1;
    unsigned char mode : 5;
    unsigned char keep2 : 1;
};

extern "C" void fn_27_617E8(Data* p) {
    p->bc = lbl_27_rodata_8B0;
    p->c0 = 4;
    p->c4 = -1;

    Vec2 v(lbl_27_rodata_8B0, lbl_27_rodata_8B0);
    p->c8 = v.x;
    p->cc = v.y;
    p->d0 = lbl_27_rodata_8B0;
    p->d4 = lbl_27_rodata_8B4;
    p->d8 = lbl_27_rodata_8B0;
    p->dc = 0;
    p->e0 = 0;
    p->e4 = lbl_27_rodata_8B0;
    p->f8 = -1;
    p->e8 = -1;
    p->ec = lbl_27_rodata_8B4;
    p->flag = 0;
    p->mode = 0;
}
