#pragma force_active on
#include <types.h>
#include <ft/ft_common_data_accesser.h>
#include <nw4r/math/math_arithmetic.h>

struct Work {
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
    virtual int v17(unsigned long);
    virtual void v18(unsigned long);
};

struct Sensor {
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
    virtual float v16();
};

struct Motion {
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
    virtual void v15(Vec3f*, int);
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
    virtual void v31(float);
};

struct Flagged {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void* v6(int);
};

struct OwnerPad {
    char pad[0x3c];
};

struct Owner : OwnerPad {
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
};

struct Modules {
    char pad0[0xc];
    Motion* motion;
    char pad1[0x4c];
    Sensor* sensor;
    char pad2[0x4];
    Work* work;
    char pad3[0x14];
    Flagged* flagged;
};

struct Accesser {
    char pad0[8];
    Owner* owner;
    char pad1[0xcc];
    Modules* modules;
};

extern "C" {
extern const float lbl_107_rodata_48[];
extern const char lbl_107_data_8DD0[], lbl_107_data_3B18[];
void* __dynamic_cast(void*, long, const void*, const void*, short);
Vec3f* fn_107_B444(Vec3f*, float, float, float);
}

extern "C" void fn_107_11E94(void*, Accesser* a) {
    const float* constants = lbl_107_rodata_48;
    Modules* modules = a->modules;
    Work* work = modules->work;
    Sensor* sensor = modules->sensor;
    Motion* motion = modules->motion;
    Flagged* flagged = modules->flagged;
    float* params = *(float**)((char*)g_ftCommonDataAccesser.getData((ftKind)0x12) + 0x84);

    if (work->v17(0x22000011) == 0) {
        float v = sensor->v16();
        float absv = nw4r::math::FAbs(v);
        if (absv >= params[0]) {
            float diff = absv - params[0];
            float sign;
            if (v > constants[2]) {
                sign = constants[0];
            } else {
                sign = constants[1];
            }
            float scaled = diff * sign;
            float f31 = scaled * params[1];
            Vec3f tmp;
            motion->v15(fn_107_B444(&tmp, f31, constants[2], constants[2]), 0);
            motion->v31(constants[2]);
            motion->v19();
            a->owner->v43();
            void* obj = __dynamic_cast(flagged->v6(0), 0, lbl_107_data_8DD0, lbl_107_data_3B18, 1);
            *(float*)((char*)obj + 0x3c) = constants[3] * f31;
            work->v18(0x22000011);
        }
    }
}
