#pragma pool_data on
#pragma pool_fp_consts on

#include <types.h>
#include <so/so_module_accesser.h>
#include <nw4r/ut/ut_algorithm.h>
#pragma force_active on

struct Prefix8 {
    char pad[8];
};

class ModuleEx : public Prefix8 {
public:
    virtual ~ModuleEx();
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
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void m25(int, Vec3f*);
    virtual Vec3f m26(int);
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void m30(int, Vec3f*);
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void v55();
    virtual void v56();
    virtual int m56(int, int);
    virtual void v58();
    virtual Vec2f m58(int, int);
};

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual int slot3();
    virtual void slot4(float);
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual float slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual Vec2f slot13(short*);
};

class FighterStatusObj {
public:
    virtual ~FighterStatusObj();
    virtual void v3();
    virtual void v4();
    virtual int m4(int, soModuleAccesser*);
};

struct EnumRaw {
    char pad0[4];
    ModuleEx* m4;
    Object_vptr_0* m8;
    Object_vptr_0* mC;
    ModuleEx* m10;
    Object_vptr_0* m14;
    char pad1[0x70 - 0x18];
    FighterStatusObj* m70;
    char pad2[8];
    Object_vptr_0* m7C;
};

struct ParamTable {
    char pad0[0xc];
    float v0c;
    float v10;
    float v14;
    float v18;
    float v1c;
    float v20;
    float v24;
    float v28;
    char pad1[0x44 - 0x2c];
    int v44;
};

struct ParamHolder {
    char pad[8];
    ParamTable* table;
};

extern "C" {
extern const float lbl_98_rodata_20[];
extern const char lbl_98_data_600[];
extern const char lbl_98_data_2F88[];

void* __dynamic_cast(void*, long, const void*, const void*, short);
void* fn_98_9530(void*);
Vec3f* fn_98_F5B0(Vec3f*, float, float, float);
void fn_98_F5C0(float*, float, float, float);
float fn_98_F0B4(float, float);
float fn_8003DDD0(const Vec2f*, const Vec2f*);
}

#pragma always_inline on
#pragma inline_depth(8)

static inline void updateRotation(
    soModuleAccesser* accesser, short one)
{
    ModuleEx* r24;
    Object_vptr_0* r25;
    Object_vptr_0* r27;
    ParamTable* p26;

    p26 = static_cast<ParamHolder*>(fn_98_9530(__dynamic_cast(
        accesser->m_stageObject, 0x3c,
        lbl_98_data_600, lbl_98_data_2F88, one)))->table;

    r27 = ((EnumRaw*)accesser->m_enumerationStart)->m14;
    r25 = ((EnumRaw*)accesser->m_enumerationStart)->m7C;
    r24 = ((EnumRaw*)accesser->m_enumerationStart)->m4;

    Vec3f vA = r24->m26(3);
    Vec3f vB;
    fn_98_F5B0(&vB, 1.0f, 1.0f, 1.0f);

    if (r27->slot3() == 0) {
        Vec2f v;
        Vec2f::copy(v,
            ((EnumRaw*)accesser->m_enumerationStart)->m10->m58(0xff, 0));

        float t =
            ((EnumRaw*)accesser->m_enumerationStart)->mC->slot9();
        float angle = fn_98_F0B4(v.m_x, v.m_y);
        float ca = 57.295780181884766f * angle;

        vA.m_x = ca * t;
        vA.m_x = vA.m_x + 57.295780181884766f * p26->v0c;

        fn_98_F5C0(reinterpret_cast<float*>(&vB),
            p26->v10, p26->v14, p26->v18);
    } else {
        short s8 = one;
        Vec2f sv;
        Vec2f::copy(sv, r25->slot13(&s8));

        float angle = fn_98_F0B4(
            static_cast<float>(
                static_cast<double>(nw4r::ut::Abs(sv.m_x))),
            sv.m_y);

        vA.m_x = 57.295780181884766f * angle;
        vA.m_x = vA.m_x + (57.295780181884766f * p26->v1c - 90.0f);

        fn_98_F5C0(reinterpret_cast<float*>(&vB),
            p26->v20, p26->v24, p26->v28);
    }

    r24->m30(3, &vA);
    r24->m25(3, &vB);
    ((EnumRaw*)accesser->m_enumerationStart)->m8->slot4(1.0f);
}

extern "C" void fn_98_F0F4(void*, soModuleAccesser* accesser)
{
    float pool;
    double bias;
    pool = 0.0f;
    pool = 0.9990000128746033f;
    pool = 1.5707963705062866f;
    pool = 0.0010000000474974513f;
    pool = 1.1920928955078125e-7f;
    pool = 1.0f;
    pool = -1.1920928955078125e-7f;
    pool = -1.0f;
    pool = 12.0f;
    pool = 1.1754943508222875e-38f;
    pool = 57.295780181884766f;
    pool = 90.0f;
    pool = 0.01745329238474369f;
    bias = 4503601774854144.0;
    pool = 9.0f;
    ParamTable* p30 = static_cast<ParamHolder*>(fn_98_9530(__dynamic_cast(
        accesser->m_stageObject, 0x3c,
        lbl_98_data_600, lbl_98_data_2F88, 1)))->table;
    updateRotation(accesser, 1);

    Vec2f s54;
    Vec2f s4c;
    short sA;

    ModuleEx* m10 =
        ((EnumRaw*)accesser->m_enumerationStart)->m10;
    FighterStatusObj* r25s =
        ((EnumRaw*)accesser->m_enumerationStart)->m70;

    sA = 1;
    Vec2f::copy(s54,
        ((EnumRaw*)accesser->m_enumerationStart)->m7C->slot13(&sA));

    if (m10->m56(1, 0) != 0) {
        s4c = m10->m58(1, 0);
        if (fn_8003DDD0(&s54, &s4c) >
            0.01745329238474369f * (90.0f + (float)p30->v44)) {
            r25s->m4(0x118, accesser);
        }
    }

    if (m10->m56(4, 0) != 0) {
        s4c = m10->m58(4, 0);
        if (fn_8003DDD0(&s54, &s4c) >
            0.01745329238474369f * (90.0f + (float)p30->v44)) {
            r25s->m4(0x118, accesser);
        }
    }

    if (m10->m56(2, 0) != 0) {
        s4c = m10->m58(2, 0);
        if (fn_8003DDD0(&s54, &s4c) >
            0.01745329238474369f * (90.0f + (float)p30->v44)) {
            r25s->m4(0x118, accesser);
        }
    }
}
