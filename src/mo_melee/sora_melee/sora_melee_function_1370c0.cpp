#include <types.h>
#include <so/so_value_accesser.h>
#include <so/so_module_accesser.h>
#pragma force_active on

class ScaleModA {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual int q4(u32 a);
    virtual void s5(int a, u32 b);
    virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void s12(u32 a);
    virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16();
    virtual u32 q17(u32 a);
    virtual void v18();
    virtual void s19(u32 a);
};

class ScaleModB {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void v21(); virtual void v22();
    virtual void s23();
};

class ScaleModC {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void s16();
};

class ScaleModD {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual void s5(int a);
};

class ScaleModE {
public:
    virtual void v0(); virtual void v1(); virtual void v2();
    virtual void s3(u32 a, void* b);
};

struct ScaleMods {
    char p0[0x0C];
    ScaleModB* b;
    char p1[0x50 - 0x10];
    ScaleModC* c;
    char p2[0x64 - 0x54];
    ScaleModA* a;
    char p3[0x70 - 0x68];
    ScaleModE* e;
    char p4[0xC4 - 0x74];
    ScaleModD* d;
};

struct ScaleAcc {
    char p[0xD8];
    ScaleMods* mods;
};

class Fighter {
public:
    enum ScalingKind { ScalingKind_0, ScalingKind_1, ScalingKind_2 };
    enum ScalingType { ScalingType_0, ScalingType_1 };
    char pad[0x60];
    ScaleAcc* m_acc;
    void startScaling(ScalingKind kind, ScalingType type);
};

#define SCALE_BLOCK                                                             \
    {                                                                           \
        ScaleAcc* a2 = m_acc;                                                   \
        a2->mods->a->s12(0x1100000B);                                           \
        a2->mods->b->s23();                                                     \
        if (a2->mods->a->q17(0x12000014) == 1) {                                \
            a2->mods->a->s19(0x12000014);                                       \
            a2->mods->d->s5(0);                                                 \
            ScaleModC* c = a2->mods->c;                                         \
            a2->mods->a->s12(0x11000011);                                       \
            c->s16();                                                           \
        }                                                                       \
        if (a2->mods->a->q17(0x12000015) == 1) {                                \
            a2->mods->a->s19(0x12000015);                                       \
            a2->mods->d->s5(1);                                                 \
            ScaleModC* c = a2->mods->c;                                         \
            a2->mods->a->s12(0x11000011);                                       \
            c->s16();                                                           \
        }                                                                       \
        a2->mods->a->s5(0, 0x10000023);                                         \
    }

#define SCALE_TAIL(n, id)                                                       \
    acc->mods->a->s5(kind, 0x10000024);                                         \
    acc->mods->a->s5(n, 0x10000023);                                            \
    acc->mods->e->s3(id, acc);

#define SCALE_CONST                                                             \
    if (kind == 1) {                                                            \
        acc->mods->a->s5(soValueAccesser::getConstantInt((soModuleAccesser*)acc, 0x5a79, 0), 0x10000021); \
    } else {                                                                    \
        acc->mods->a->s5(soValueAccesser::getConstantInt((soModuleAccesser*)acc, 0x5a7b, 0), 0x10000022); \
    }

void Fighter::startScaling(ScalingKind kind, ScalingType type)
{
    ScaleAcc* acc = m_acc;

    if (acc->mods->a->q17(0x12000021) == 1 || acc->mods->a->q17(0x12000032) == 1 ||
        acc->mods->a->q17(0x12000018) == 1) {
        return;
    }

    int cnt = acc->mods->a->q4(0x10000023);
    int val = acc->mods->a->q4(0x10000024);

    if (kind == 2 || val != kind) {
        switch (type) {
        case 0:
            if (val != kind) SCALE_BLOCK
            SCALE_TAIL(4, 0xF2)
            break;
        case 1:
            if (val != kind) SCALE_BLOCK
            SCALE_TAIL(6, 0xF3)
            break;
        }
    } else {
        switch (type) {
        case 0:
            if (cnt < 3) {
                if (val != kind) SCALE_BLOCK
                SCALE_TAIL(4, 0xF2)
            } else if (cnt > 4) {
                SCALE_TAIL(1, 0xF3)
            } else {
                SCALE_CONST
            }
            break;
        case 1:
            if (cnt < 3) {
                if (val != kind) SCALE_BLOCK
                SCALE_TAIL(6, 0xF3)
            } else if (cnt < 5) {
                SCALE_TAIL(2, 0xF2)
            } else {
                SCALE_CONST
            }
            break;
        }
    }
}
