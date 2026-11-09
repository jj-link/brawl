#include <revolution/types.h>
#include <nw4r/g3d/g3d_obj.h>
#pragma force_active on
typedef unsigned char u8;
class MenuObject {
    u8 padding[0x5c];
public:
    virtual void fn(int arg);
};
extern "C" void fn_800B8A0C(void*, int);
extern "C" void __dl__FPv(void*);
extern "C" void* fn_80108A04(void* object, int deleting) {
    if (object) {
        u8* cursor = (u8*)object;
        for (int i = 0; i < 3; ++i, cursor += 4) {
            nw4r::g3d::G3dObj* entry = *reinterpret_cast<nw4r::g3d::G3dObj**>(cursor + 0x14);
            if (entry) entry->Destroy();
        }
        cursor = (u8*)object;
        for (int i = 0; i < 5; ++i, cursor += 4) {
            MenuObject* entry = *reinterpret_cast<MenuObject**>(cursor);
            if (entry) entry->fn(1);
        }
        void* entry = *reinterpret_cast<void**>((u8*)object + 0x20);
        if (entry) {
            fn_800B8A0C(entry, 1);
            *reinterpret_cast<void**>((u8*)object + 0x20) = 0;
        }
        if (deleting > 0) __dl__FPv(object);
    }
    return object;
}