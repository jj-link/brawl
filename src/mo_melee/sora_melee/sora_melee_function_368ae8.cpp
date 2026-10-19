#pragma force_active on
extern "C" {
typedef struct Sub {
    char pad[0x18];
    float f18;
} Sub;

typedef struct Obj {
    int pad0;
    Sub *sub;
    int pad8;
    float xc;
    float x10;
} Obj;

extern unsigned char lbl_27_data_91F78;
extern const float lbl_27_rodata_7B20;

void fn_27_368AE8(Obj *p) {
    float y;
    float x;
    float d;
    float v;
    if (!lbl_27_data_91F78) {
        return;
    }
    y = p->x10;
    x = p->xc;
    d = y - x;
    v = y - d * p->sub->f18;
    p->xc = v;
    if (v < lbl_27_rodata_7B20) {
        p->xc = lbl_27_rodata_7B20;
    }
}
}
