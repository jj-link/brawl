#include <types.h>
#include <so/so_value_accesser.h>
#include <so/so_module_accesser.h>
#pragma force_active on

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2(void*, int, int, float);
    virtual void slot3();
    virtual void slot4();
    virtual void slot5(u32, int, int, int);
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual float slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual float slot16();
    virtual u32 slot17(u32, void*);
};

extern "C" void fn_27_167D60(void*, soModuleAccesser* obj) {
    float scale = reinterpret_cast<Object_vptr_0*>(*(void**)(*(u8**)((u8*)obj + 0xD8) + 0xC))->slot9();
    float v = reinterpret_cast<Object_vptr_0*>(*(void**)(*(u8**)((u8*)obj + 0xD8) + 0x5C))->slot16();
    if (v * scale < soValueAccesser::getConstantFloat(obj, 0xC31, 0)) {
        char* p = (char*)soValueAccesser::getConstantIndefinite(obj, 0xA80A, 0);
        reinterpret_cast<Object_vptr_0*>(*(void**)(*(u8**)((u8*)obj + 0xD8) + 0x48))->slot2(p + 0x14, 1, 0, scale);
    }
    if (reinterpret_cast<Object_vptr_0*>(*(void**)(*(u8**)((u8*)obj + 0xD8) + 0x64))->slot17(0x12000013, *(void**)((u8*)obj + 0xD8)) == 1) {
        reinterpret_cast<Object_vptr_0*>(*(void**)(*(u8**)((u8*)obj + 0xD8) + 0x50))->slot5(0x1FAC, 0, 0, 0);
    }
}
