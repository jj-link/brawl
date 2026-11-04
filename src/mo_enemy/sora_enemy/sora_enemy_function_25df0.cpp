#pragma force_active on
#include <em/em_external_value_accesser.h>
#include <em/em_area_module_impl.h>

namespace abi {
class soAnimCmdEventObserver {
public:
    virtual void addObserver();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void fn_41_12100();
    virtual void fn_41_13608();
    virtual void fn_41_13600();
    virtual void fn_41_135BC();
    virtual void fn_41_12784();
};
class soNullable {
public:
    virtual void isNull();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual float slot9();
};
class Class_6E20 {
public:
    virtual void fn_41_3516C();
    virtual void fn_41_34F30();
    virtual void fn_41_350A4();
    virtual void fn_41_350AC();
    virtual void fn_41_350B4();
    virtual void fn_41_350BC();
    virtual void fn_41_350DC();
    virtual void fn_41_350C4();
    virtual void fn_41_35120();
    virtual float fn_41_350CC();
};
}

struct V2 {
    float x, y;
    V2& operator=(const V2& v) {
        x = v.x;
        y = v.y;
        return *this;
    }
};

extern "C" {
extern char __RTTI__5Enemy[];
extern char __RTTI__11StageObject[];
extern float lbl_41_rodata_D54;
extern float lbl_41_rodata_D58;
void* __dynamic_cast(void*, long, const void*, const void*, short);
float fn_41_23CD4(void*, unsigned long);
float fn_41_23E0C(void*, unsigned long);
V2 fn_41_24278(V2, float, float, float);
Vec3f* fn_41_5AC4(Vec3f*, float, float, float);
Vec3f* fn_41_534C(Vec3f*, const Vec3f&);
float fn_41_25BD0(float, const Vec3f&, const Vec3f&);

float fn_41_25DF0(void* acc, unsigned long target, V2* first, unsigned long mode) {
    Vec3f pos = emAreaModuleImpl::getTargetPos((soModuleAccesser*)acc, target, true);
    float scale = lbl_41_rodata_D54;
    if (mode == 1)
        scale = fn_41_23CD4(acc, target);
    *first = fn_41_24278(*first, scale, fn_41_23E0C(acc, target), lbl_41_rodata_D58);
    pos.m_x += first->x;
    pos.m_y += first->y;
    Vec3f center;
    fn_41_5AC4(&center, lbl_41_rodata_D58, lbl_41_rodata_D58, lbl_41_rodata_D58);
    Vec3f centerCopy;
    Vec3f posCopy;
    fn_41_534C(&center, emExternalValueAccesser::getCenterPos(
        (Enemy*)__dynamic_cast(*(void**)((char*)acc + 8), 0x3c,
          __RTTI__5Enemy, __RTTI__11StageObject, 1)));
    abi::soNullable* posture = *(abi::soNullable**)(*(char**)((char*)acc + 0xd8) + 0xc);
    float angle = posture->slot9();
    __memcpy(&posCopy, &pos, sizeof(Vec3f));
    __memcpy(&centerCopy, &center, sizeof(Vec3f));
    return fn_41_25BD0(angle, centerCopy, posCopy);
}
}