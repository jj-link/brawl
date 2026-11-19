#include <nw4r/ut/ut_algorithm.h>
#include <mt/mt_vector.h>
#include <so/situation/so_situation_module_impl.h>

#pragma force_active on

struct V2 {
    float m_x;
    float m_y;
};

struct Words {
    int x;
    int y;
};

union Pair {
    Words bits;
    V2 vec;
};

struct GroundBase {
    char pad[8];
};

class GroundView : public GroundBase {
public:
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
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
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
    virtual bool touch(int, int);
    virtual void v56();
    virtual Words normal(int, int);
    virtual void v58();
    virtual void v59();
    virtual void v60();
    virtual void v61();
    virtual void v62();
    virtual void v63();
    virtual void v64();
    virtual void v65();
    virtual void v66();
    virtual void v67();
    virtual void v68();
    virtual void v69();
    virtual void v70();
    virtual void v71();
    virtual void v72();
    virtual void v73();
    virtual void v74();
    virtual void v75();
    virtual void v76();
    virtual void v77();
    virtual void v78();
    virtual void v79();
    virtual void v80();
    virtual void v81();
    virtual void v82();
    virtual void v83();
    virtual void v84();
    virtual void v85();
    virtual void v86();
    virtual void v87();
    virtual void v88();
    virtual void v89();
    virtual float friction(int);
};

struct Modules {
    char pad[0x10];
    void* ground;
    soSituationModule* situation;
};

struct Object {
    char pad[0xd8];
    Modules* modules;
};

struct Energy {
    char pad[8];
    V2 speed;
    V2 accel;
    V2 stable;
    V2 brake;
    V2 limit;
    unsigned char slope;
    unsigned char friction;
    char pad2[2];
    unsigned int flags;
};

extern "C" V2 fn_27_899AC(V2*, V2*);
extern "C" void fn_8003DBA8(V2*);
extern "C" const float lbl_27_rodata_5FB0[];

extern "C" void fn_27_2BDFE4(Energy* e, Object* o) {
    const float* lbl_27_rodata_5FB0 = &::lbl_27_rodata_5FB0[0];
    V2 accel = e->accel;
    V2 brake = e->brake;

    if ((e->friction || e->slope) &&
        o->modules->situation->getKind() == 0 &&
        ((GroundView*)o->modules->ground)->touch(255, 0)) {
        if (e->friction == 1) {
            float f = ((GroundView*)o->modules->ground)->friction(0);
            if (lbl_27_rodata_5FB0[0] != f) {
                accel.m_x *= f;
                accel.m_y *= f;
                brake.m_x *= f;
                brake.m_y *= f;
            }
        }

        if (e->slope == 1) {
            Pair normal;
            normal.bits = ((GroundView*)o->modules->ground)->normal(8, 0);
            accel = fn_27_899AC(&accel, &normal.vec);
        }
    }

    V2 stable = e->stable;
    e->speed.m_x += accel.m_x;
    e->speed.m_y += accel.m_y;

    if (stable.m_x < lbl_27_rodata_5FB0[1])
        stable.m_x = lbl_27_rodata_5FB0[1];
    if (stable.m_y < lbl_27_rodata_5FB0[1])
        stable.m_y = lbl_27_rodata_5FB0[1];

    if (e->speed.m_x > stable.m_x) {
        e->speed.m_x -= brake.m_x;
        if (e->speed.m_x < stable.m_x)
            e->speed.m_x = stable.m_x;
    } else {
        e->speed.m_x += brake.m_x;
        if (e->speed.m_x > stable.m_x)
            e->speed.m_x = stable.m_x;
    }

    if (e->speed.m_y > stable.m_y) {
        e->speed.m_y -= brake.m_y;
        if (e->speed.m_y < stable.m_y)
            e->speed.m_y = stable.m_y;
    } else {
        e->speed.m_y += brake.m_y;
        if (e->speed.m_y > stable.m_y)
            e->speed.m_y = stable.m_y;
    }

    if (e->flags & 0x40) {
        float sq;
        float limit = lbl_27_rodata_5FB0[1];
        if (e->limit.m_x >= limit)
            limit += e->limit.m_x;
        if (e->limit.m_y >= limit)
            limit += e->limit.m_y;

        if (limit >= lbl_27_rodata_5FB0[1]) {
            sq = e->speed.m_x * e->speed.m_x +
                 e->speed.m_y * e->speed.m_y;
            float length = lbl_27_rodata_5FB0[1];

            if ((float)(double)nw4r::ut::Abs(sq) <= lbl_27_rodata_5FB0[2]) {
                length = lbl_27_rodata_5FB0[1];
            } else {
                length = sq * rsqrtf(sq);
            }

            if (length > limit) {
                if (limit <= lbl_27_rodata_5FB0[1]) {
                    e->speed.m_y = lbl_27_rodata_5FB0[1];
                    e->speed.m_x = lbl_27_rodata_5FB0[1];
                } else {
                    fn_8003DBA8(&e->speed);
                    e->speed.m_x *= limit;
                    e->speed.m_y *= limit;
                }
            }
        }
    } else {
        if (e->limit.m_x >= lbl_27_rodata_5FB0[1]) {
            if ((e->flags & 1) && e->speed.m_x > e->limit.m_x)
                e->speed.m_x = e->limit.m_x;
            else if ((e->flags & 2) && e->speed.m_x < -e->limit.m_x)
                e->speed.m_x = -e->limit.m_x;
        }

        if (e->limit.m_y >= lbl_27_rodata_5FB0[1]) {
            if ((e->flags & 4) && e->speed.m_y > e->limit.m_y)
                e->speed.m_y = e->limit.m_y;
            else if ((e->flags & 8) && e->speed.m_y < -e->limit.m_y)
                e->speed.m_y = -e->limit.m_y;
        }
    }
}
