#include <so/so_module_accesser.h>
#pragma force_active on

class FnModule {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual Vec3f getPos();
    virtual void setPos(Vec3f* in);
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
    virtual void slot20();
    virtual void slot21();
    virtual float getScale();
};

struct FnInner {
    char pad[0xc];
    FnModule* module;
};

struct FnAccesser {
    char pad[0xd8];
    FnInner* inner;
};

extern "C" {
extern float getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(void* accesser, unsigned int id, unsigned int index);
extern float lbl_27_rodata_22F4;
extern float lbl_27_rodata_22FC;
}

extern "C" void fn_27_176D6C(void* arg0, FnAccesser* obj, float target, float limit, int interp) {
    Vec3f pos = obj->inner->module->getPos();
    float first = obj->inner->module->getScale();
    float c = getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(obj, 0xbe5, 0);
    float value = c * first;
    value *= obj->inner->module->getScale();
    float f0 = target - value;
    float original = pos.m_y;
    if (f0 < pos.m_y) {
        if (interp == 0) {
            pos.m_y = f0;
        } else {
            pos.m_y = pos.m_y + lbl_27_rodata_22F4 * (f0 - pos.m_y);
        }
    }
    if (limit > pos.m_y) {
        limit += lbl_27_rodata_22FC;
        if (interp == 0) {
            pos.m_y = limit;
        } else {
            pos.m_y = original + lbl_27_rodata_22F4 * (limit - original);
        }
    }
    obj->inner->module->setPos(&pos);
}
