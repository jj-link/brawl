#pragma force_active on
#pragma use_lmw_stmw on

typedef unsigned char u8;
typedef signed int s32;

struct Entry {
    virtual void pad0();
    virtual void pad1();
    virtual void pad2();
    virtual void pad3();
    virtual void pad4();
    virtual void pad5();
    virtual void pad6();
    virtual void pad7();
    virtual void funcA(s32*);
    virtual void funcB(s32);
};

struct Container {
    s32 pad0[4];
    Entry** arr;
    s32 count;
};

extern "C" s32 fn_802AF0B0(Container* arg0, s32 arg1) {
    s32 acc;
    s32 i = 0;
    acc = arg1;

    for (; i < arg0->count; i++) {
        Entry* e = *(Entry**)((u8*)arg0->arr + i * 8);
        e->funcB(acc);
        s32 stride;
        e->funcA(&stride);
        acc += stride * 0x10;
    }

    return arg1;
}
