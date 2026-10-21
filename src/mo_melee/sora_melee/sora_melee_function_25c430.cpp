#pragma force_active on

struct Self {
    unsigned char pad0[0x48];
    int state;
    unsigned int count;
    unsigned char pad50[0x14];
    unsigned int limit;
};

struct Context {
    unsigned char pad0[0x44];
    int kind;
    unsigned char pad48[0x152];
    unsigned char flag19A;
    unsigned char flag19B;
    unsigned char flag19C;
};

struct itManager;

extern itManager* lbl_27_bss_6A34;
extern Context* lbl_27_bss_5668;

extern "C" itManager* getInstance__9itManagerFv();
extern "C" int fn_27_2A8674(itManager*);

inline Context* castContext(Context* p) {
    if (p && p->kind == 0x3D)
        return p;
    return 0;
}

extern "C" void fn_27_25C430(Self* self) {
    if (self->count < self->limit) {
        if (lbl_27_bss_6A34) {
            fn_27_2A8674(getInstance__9itManagerFv());
        }
        ++self->count;
    } else {
        Context* p = lbl_27_bss_5668;
        if (!p->flag19A) {
            if (castContext(p)->flag19B)
                self->state = 10;
        } else {
            self->state = 10;
        }
    }

    Context* p = lbl_27_bss_5668;
    if (!p->flag19A) {
        if (castContext(p)->flag19C)
            self->state = 10;
    }
}
