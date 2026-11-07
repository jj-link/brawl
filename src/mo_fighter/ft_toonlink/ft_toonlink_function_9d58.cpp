#pragma force_active on

extern "C" void fn_27_13138C(void*, int, int, void*, void*);

class Class8E20 {
public:
    virtual void fn_121_22F8();
    virtual void fn_121_12B5C();
    virtual void fn_121_14840();
    virtual void fn_121_14838();
    virtual void fn_121_14830();
    virtual void fn_121_14828(int, int);
    virtual void fn_121_14820();
    virtual void fn_121_14818();
    virtual void fn_121_14810();
    virtual void fn_121_14808();
    virtual void fn_121_14800();
    virtual void fn_121_147F8();
    virtual void fn_121_147F0();
    virtual void fn_121_147E8();
    virtual void fn_121_14798();
    virtual void fn_121_147E0();
    virtual void fn_121_147D0();
    virtual void fn_121_147C0();
    virtual void fn_121_147B0();
    virtual void fn_121_147A0(int);
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

struct ObjV5 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v5(int, int, bool);
};

struct Inner {
    char pad0[0x58];
    ObjV5* v58;
    char pad1[0x64 - 0x5c];
    Class8E20* v64;
    char pad2[0xa8 - 0x68];
    ObjA8* va8;
};

struct Holder {
    char pad[0xd8];
    Inner* inner;
};

extern "C" void fn_121_9D58(void* self, int id, int a3, void* a4, Holder* h) {
    fn_27_13138C(self, id, a3, a4, h);
    switch (id) {
    case 0x0:
    case 0x12:
        break;
    case 0x33: {
        Class8E20* o = h->inner->v64;
        o->fn_121_147A0(0x1200003E);
        o->fn_121_147A0(0x12000040);
        o->fn_121_14828(0, 0x10000040);
        break;
    }
    }
    ObjA8* a8 = h->inner->va8;
    ObjV5* v5 = h->inner->v58;
    if (a8->v16(0) == 1) {
        if (a8->v17(0) == 1) {
            v5->v5(1, 1, true);
        }
        v5->v5(2, 1, true);
    } else {
        v5->v5(1, 0, true);
        v5->v5(2, 0, true);
    }
    h->inner->v64->fn_121_147A0(0x12000041);
}
