#include <types.h>
#include <nw4r/g3d/g3d_obj.h>
#pragma force_active on

struct Obj {
    u8 pad0[0x40];
    void* field40;
    u8 pad44[0x10];
    void* field54;
    u8 pad58[8];
    nw4r::g3d::G3dObj* field60;
};

extern "C" void fn_801AC6EC(void*);
extern "C" void fn_8000D3EC(Obj*, void*);

extern "C" void fn_8000D67C(Obj* self) {
    if (self->field60 != 0) {
        fn_801AC6EC(self->field40);
        self->field60->Destroy();
    }
    self->field60 = 0;
    if (self->field54 != 0) {
        fn_8000D3EC(self, self->field54);
    }
}