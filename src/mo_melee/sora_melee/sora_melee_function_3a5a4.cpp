#include <types.h>
#pragma force_active on

extern "C" float fn_27_379A0(void*, void*);

class Obj {
public:
    virtual void v0() = 0;
    virtual void* v1() = 0;
};

extern "C" float fn_27_3A5A4(void* self, void* arg2, u32 type) {
    if (type == 1) {
        return *reinterpret_cast<float*>(reinterpret_cast<u8*>(self) + 0x38);
    }
    Obj* obj = *reinterpret_cast<Obj**>(reinterpret_cast<u8*>(self) + 0x30);
    void* p = obj->v1();
    return fn_27_379A0(reinterpret_cast<u8*>(self) + 0x68, *reinterpret_cast<void**>(reinterpret_cast<u8*>(p) + 0x88));
}
