#include <types.h>
#pragma force_active on

class Object {
public:
    virtual void slot0();    // 0x08
    virtual void slot1();    // 0x0c
    virtual void slot2();    // 0x10
    virtual void slot3();    // 0x14
    virtual void slot4();    // 0x18
    virtual void slot5();    // 0x1c
    virtual void slot6(s32, s32);  // 0x20
};

extern "C" void fn_800B22B8(void* self) {
    Object* obj = *reinterpret_cast<Object**>(reinterpret_cast<char*>(self) + 0x10);
    obj->slot6(2, 0);
    obj->slot6(5, 0);
}
