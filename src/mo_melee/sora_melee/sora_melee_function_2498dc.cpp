#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;

struct Data {
    u8 pad0[8];
    u8 kind;
    u8 mode;
    u8 padA;
    unsigned char unused : 2;
    unsigned char flag : 1;
    unsigned char unused2 : 5;
    u8 padC[0x14];
    int value;
};

struct Obj {
    u8 pad0[0x2C];
    unsigned char flagsHigh : 6;
    unsigned char flagBit : 1;
    unsigned char flagsLow : 1;
    u8 pad2D[0x13];
    u8 active;
    u8 pad41[3];
    Data* data;
    u8 pad48[0x88];
    bool d0;
    bool d1;
    bool d2;
    bool d3;
    u8 padD4[2];
    bool d6;
    u8 padD7[5];
    bool dc;
    u8 padDD[3];
    int e0;
    u8 padE4[4];
    int e8;
    u8 padEC[4];
    int f0;
    u8 padF4[0x138];
    int state;
};

extern "C" void fn_27_248010(Obj*);
extern "C" void fn_27_24AC3C(Obj*);
extern "C" Obj* lbl_27_bss_59A8;

inline bool special(Data* p) {
    return (((u32)p->mode >> 5) & 7) == 2 &&
           (((u32)p->kind >> 2) & 63) == 7;
}

extern "C" void fn_27_2498DC(Obj* p) {
    fn_27_248010(p);
    fn_27_24AC3C(p);
    lbl_27_bss_59A8 = p;

    if (p->state == 1 && p->data->value == 0)
        p->d3 = true;

    p->d2 = p->data->flag;
    p->d1 = (p->d2 || (((u32)p->data->mode >> 5) & 7) == 1) ||
            special(p->data);
    p->dc = (((u32)p->data->mode >> 5) & 7) == 1 ||
            special(p->data);

    int value = p->data->value;
    if (value) {
        if (p->d3) {
            if (p->d6)
                p->e8 = value;
        } else {
            p->e0 = value;
            p->d0 = true;
            p->f0 = 302;
        }
    }

    p->flagBit = 0;
    p->active = true;
}
