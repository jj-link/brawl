#pragma force_active on
extern "C" void fn_27_13138C(void*, int, int, void*, void*);

struct Obj64 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5(int, int);
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void fn_93_1474C(int);
    virtual void fn_93_14794(int);
    virtual void fn_93_14784(int);
    virtual void fn_93_14774(int);
    virtual void fn_93_14764(int);
    virtual void fn_93_14754(int);
};

struct ObjA8 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual unsigned int v16(int);
    virtual int v17(int);
};

struct Obj58 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void fn_93_14798(int, int, bool);
};

struct Inner {
    char pad0[0x58];
    Obj58* v58;
    char pad1[0x64 - 0x5C];
    Obj64* v64;
    char pad2[0xA8 - 0x68];
    ObjA8* va8;
};

struct Holder {
    char pad[0xD8];
    Inner* inner;
};

extern "C" void fn_93_9D58(void* self, int status, int prev, void* data, Holder* holder) {
    fn_27_13138C(self, status, prev, data, holder);
    switch (status) {
        case 0x0:
        case 0x12:
            break;
        case 0x33: {
            Obj64* o64 = holder->inner->v64;
            o64->fn_93_14754(0x1200003E);
            o64->fn_93_14754(0x12000040);
            o64->v5(0, 0x10000040);
            break;
        }
        default:
            break;
    }
    ObjA8* a8 = holder->inner->va8;
    Obj58* v58 = holder->inner->v58;
    if (a8->v16(0) == 1) {
        if (a8->v17(0) == 1) {
            v58->fn_93_14798(1, 1, true);
        }
        v58->fn_93_14798(2, 1, true);
    } else {
        v58->fn_93_14798(1, 0, true);
        v58->fn_93_14798(2, 0, true);
    }
    holder->inner->v64->fn_93_14754(0x12000041);
}