#pragma opt_propagation off
#include <types.h>
#include <mu/mu_object.h>
#pragma force_active on
extern "C" {
extern float lbl_2_rodata_EA0;
void fn_800B330C(void*, void*, int);
}
struct MenuAnim { u32 x0; u32 x4; u32 x8; u32 xC; u32 x10; };
extern "C" MenuAnim lbl_2_data_31C8[];

struct Node {
    virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3();
    virtual void f4(); virtual void f5(); virtual void f6(); virtual void f7();
    virtual void f8(); virtual float getFrame();
};
struct MenuObjects { char pad[0x264]; MuObject* object; };
struct Other { char pad[0x40]; void* value; };
struct Handler {
    virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3();
    virtual void f4(); virtual void f5(); virtual void f6(); virtual void f7();
    virtual void f8(); virtual void f9(); virtual void f10(); virtual void f11();
    virtual void f12(); virtual void apply(void*);
};
struct Menu {
    char pad[0x64c]; MenuObjects* objects; Other* other; Handler* handler;
    char pad658[0x18]; int state; char pad674[8]; int index;
};
extern "C" void fn_2_28968(Menu* self) {
    switch (self->state) {
    case 0: case 1: break;
    case 3: case 5:
        if (((Node**)((char*)self->objects->object->m_modelAnim + 0xc))[0]->getFrame() == lbl_2_rodata_EA0 && self->state != 0) {
            self->state = 0;
            self->handler->apply(self->other->value);
        }
        break;
    case 2: case 4:
        if (((Node**)((char*)self->objects->object->m_modelAnim + 0xc))[0]->getFrame() == lbl_2_rodata_EA0 && self->state != 1) {
            int index = self->index;
            int flags = 0;
            self->state = 1;
            if (index > 0) flags |= 2;
            if (index < 0x17) flags |= 1;
            self->objects->object->setFrameVisible((float)flags);
            int idx = 1;
            fn_800B330C(self->objects->object, &lbl_2_data_31C8[idx], 0);
        }
        break;
    }
}
