#pragma force_active on

struct Inner {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual float getFrame();
};

struct Listener {
    unsigned char pad[0xc];
    Inner* inner;
};

struct Obj {
    unsigned char pad[0xc];
    void* model;
    unsigned char pad10[4];
    Listener* listener;
};

struct Menu {
    unsigned char pad0[0x138];
    int count;
    unsigned char pad13c[0x30];
    Obj* objs[1];
};

extern "C" void fn_801AAFF0(void*, int);
extern "C" void fn_801AB014(void*, int);
extern "C" const float lbl_10_rodata_2F0;

extern "C" void fn_10_D5F0(Menu* menu) {
    const float threshold = lbl_10_rodata_2F0;
    Obj* o;
    char* p = (char*)menu;
    int i = 0;
    for (; i < menu->count; i++) {
        o = *(Obj**)(p + 0x16c);
        float f = o->listener->inner->getFrame();
        if (f <= threshold) {
            fn_801AAFF0(o->model, i + 0x17);
            fn_801AB014(o->model, i + 0x17);
        }
        p += 4;
    }
}
