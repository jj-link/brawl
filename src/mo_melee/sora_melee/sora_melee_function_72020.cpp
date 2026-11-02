#pragma force_active on

extern "C" void fn_27_7030C(void* obj, int a, int b, int c, float f);
extern "C" char lbl_27_data_8390[];
extern "C" const float lbl_27_rodata_9B8;

struct Src {
    virtual void v0();
    virtual void v1();
    virtual void** getAt(int i);
    virtual void v3();
    virtual int getCount();
};

struct Sub {
    virtual void fill(short* a, void* l, char* d);
};

struct LV {
    virtual void v0();
    virtual void*** at(int i);
};

struct Owner {
    char pad[0x20];
    Src* src;
};

struct L {
    void** vt;
    char* d;
    unsigned bits;
    char pad[0x50];
};

extern "C" void fn_27_72020(Owner* self, short* id, int idx) {
    short v = *id;
    if (v == -1) {
        int n = self->src->getCount();
        for (int i = 0; i < n; i++) {
            fn_27_7030C(*self->src->getAt(i), 0, idx, 1, lbl_27_rodata_9B8);
        }
    } else {
        short s = v;
        L l;
        l.vt = (void**)lbl_27_data_8390;
        char* d = lbl_27_data_8390 + 0x48;
        l.d = d;
        l.bits &= 0x1FFF;
        ((Sub*)((char*)self->src + 0xc))->fill(&s, &l, d);
        int n = ((int)((l.bits << 12) & 0xFE000000)) >> 26;
        for (int i = 0; i < n; i++) {
            fn_27_7030C(**((LV*)&l)->at(i), 0, idx, 1, lbl_27_rodata_9B8);
        }
    }
}
