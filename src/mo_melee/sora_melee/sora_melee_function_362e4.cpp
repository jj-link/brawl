#include <types.h>
#pragma force_active on

extern "C" {
void fn_27_37D7C(void*, void*, s32, s32);
u32 fn_27_38048(void*);
}

class Obj {
public:
    virtual void v0();
    virtual Obj* v1();
    u8 pad[0x30];
    Obj* m34;
};

extern "C" {
void fn_27_362E4(void* self) {
    Obj* obj = *(Obj**)((char*)self + 0x8);
    Obj* r31 = obj->v1();
    fn_27_37D7C(r31, r31->m34, 1, 0);
    if (fn_27_38048(r31) == 1) {
        fn_27_37D7C(r31, (char*)r31 + 0x28, 1, 0);
    }
}
}
