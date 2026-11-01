#include <mt/mt_vector.h>
#include <orch_helpers.h>
#include <nw4r/ut/ut_algorithm.h>
#pragma force_active on

extern "C" int fn_27_30FACC(void*, unsigned int, int, void*, unsigned int);
extern "C" int fn_27_30FA2C(void*, unsigned int, int, void*, unsigned int);
extern "C" float fn_27_192278(void*, unsigned long);
extern "C" float rsqrtf__Ff(float);

extern "C" unsigned char lbl_27_bss_7B0C[];
extern "C" const float lbl_27_rodata_8030;
extern "C" const float lbl_27_rodata_8038;

struct OwnerBase { char pad[0x3c]; };

class Owner : public OwnerBase {
public:
    virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3();
    virtual void f4(); virtual void f5(); virtual void f6(); virtual void f7();
    virtual void f8(); virtual void f9(); virtual void f10(); virtual void f11();
    virtual void f12(); virtual void f13(); virtual void f14(); virtual void f15();
    virtual void f16(); virtual void f17(); virtual void f18(); virtual void f19();
    virtual void f20(); virtual void f21(); virtual void f22(); virtual void f23();
    virtual void f24(); virtual void f25(); virtual void f26(); virtual void f27();
    virtual void f28(); virtual void f29(); virtual void f30(); virtual void f31();
    virtual void f32(); virtual void f33(); virtual void f34(); virtual void f35();
    virtual void f36(); virtual void f37(); virtual void f38(); virtual void f39();
    virtual int get();
};

class PositionModule {
public:
    virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3();
    virtual Vec3f get();
};

class ModelModule {
public:
    virtual void f0(); virtual void f1(); virtual void f2();
    virtual void update(int, void*, void*);
    virtual void f4(); virtual void f5(); virtual void f6(); virtual void f7();
    virtual void f8(); virtual void f9(); virtual void f10(); virtual void f11();
    virtual void f12(); virtual void f13(); virtual void f14(); virtual void f15();
    virtual int getStatus();
};

struct ModuleAccesser {
    char pad[0x0c];
    PositionModule* position;
    char pad2[0x60];
    ModelModule* model;
};

struct Object { char pad[0xd8]; ModuleAccesser* accesser; };
struct Fighter {
    char pad[8];
    Owner* owner;
    char pad2[0xcc];
    ModuleAccesser* accesser;
};

extern "C" void fn_27_3BB430(void*, int arg1, int arg2, Object* arg3,
                             Fighter* arg4) {
    if (arg2 != 1)
        return;

    if (arg4->owner->get() == 0x2e && arg1 != 0xd)
        return;
    if (arg1 != 0xb)
        return;

    Vec3f first = arg3->accesser->position->get();

    int status = fn_27_30FACC(lbl_27_bss_7B0C, 0,
                              arg4->accesser->model->getStatus(), arg4, 1);
    unsigned int ok;
    if (status != 0 && status != 0x12e) {
        ok = 0;
    } else {
        Vec3f second = arg4->accesser->position->get();
        Vec3f delta;
        Vec3fSub_vb75923(&delta, &first, &second);

        float length2 =
            delta.m_x * delta.m_x + delta.m_y * delta.m_y + delta.m_z * delta.m_z;
        float length;
        float abs_len2 = (float)(double)__fabsf(length2);
        if (abs_len2 <= lbl_27_rodata_8038)
            length = lbl_27_rodata_8030;
        else
            length = length2 * rsqrtf__Ff(length2);

        ok = (length > fn_27_192278(arg4, 0xfa8)) ? 0 : 1;
    }

    if (ok == 1) {
        int result = fn_27_30FA2C(lbl_27_bss_7B0C, 0, 0x12e, arg4, 0);
        arg4->accesser->model->update(result, arg4, arg4->accesser);
    }
}
