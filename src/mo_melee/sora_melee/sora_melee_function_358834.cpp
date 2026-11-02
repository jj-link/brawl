#include <types.h>
#include <mt/mt_vector.h>
#pragma force_active on

struct Base8 {
    char pad[8];
};

struct ChainB {
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
    virtual void v14();
    virtual s32 v15();
};

struct ChainA : Base8 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual ChainB* v4();
};

struct ModelObj {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual Vec3f v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual float v9();
};

struct TreeObj {
    virtual void v0();
    virtual void v1();
    virtual TreeObj* v2();
};

struct SetObj {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4(s32 a, s32 b);
};

struct GetObj {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual s32 v4(s32 a);
};

struct Modules {
    ChainA* unk0;
    char pad4[0x8];
    ModelObj* unkC;
    char pad10[0x8];
    TreeObj* unk18;
    char pad1C[0x38];
    SetObj* unk54;
    char pad58[0xC];
    GetObj* unk64;
};

struct Data {
    char pad[0x28];
    s32 unk28;
};

struct Access {
    char pad0[0x8];
    Data* unk8;
    char pad0C[0xCC];
    Modules* unkD8;
};

extern "C" void fn_110_11C60(void* self, s32 a, s32 b, s32 c, void* d, Vec3f* e, float f);

extern "C" s32 fn_27_358834(void* unused, Data* self, Access* acc) {
    TreeObj* tree;
    ChainA* chain;
    s32 r29;
    ModelObj* model;
    s32 r27;
    float f31;
    s32 r6;

    r27 = acc->unkD8->unk64->v4(0x10000044);
    model = acc->unkD8->unkC;
    tree = acc->unkD8->unk18;
    chain = acc->unkD8->unk0;
    r29 = acc->unk8->unk28;
    f31 = model->v9();
    Vec3f sp8 = model->v4();
    tree = tree->v2()->v2();
    r6 = chain->v4()->v15();
    fn_110_11C60(self, r29, r27, r6, tree, &sp8, f31);
    acc->unkD8->unk54->v4(6, self->unk28);
    return 1;
}
