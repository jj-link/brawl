#pragma force_active on
typedef short s16;
typedef unsigned int u32;

extern "C" {
extern char lbl_41_data_18740[];
extern char lbl_41_data_3E50[];
void fn_41_2D038(void* self, int zero, s16 val, void* arr, char* data);
}

struct emIfc {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual s16 slot7();
    virtual void slot8();
    virtual void slot9();
};

struct emZ {
    char pad[8];
    emIfc ifc;
};

struct emX {
    char pad0[0x80];
    emZ* z;
    char pad1[0x3c];
    void* p;
};

struct emOwner {
    char pad[0xd8];
    emX* x;
};

struct emBlk {
    int a;
    int b;
    int* c;
    void* d;
};

extern "C" void* fn_41_5B21C(void* self, emOwner* owner) {
    emBlk blk;
    *(char**)self = lbl_41_data_18740;
    void* p = owner->x->p;
    blk.a = 1;
    blk.b = 0x33;
    blk.c = &blk.a;
    blk.d = p;
    s16 r = owner->x->z->ifc.slot7();
    fn_41_2D038((char*)self + 4, 0, r, &blk.c, lbl_41_data_3E50);
    return self;
}
