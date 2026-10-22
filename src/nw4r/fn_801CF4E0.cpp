#include <types.h>
#pragma force_active on

extern "C" s32 OSDisableInterrupts();
extern "C" void OSRestoreInterrupts(s32);
extern "C" void Erase__Q44nw4r2ut6detail12LinkListImplFPQ34nw4r2ut12LinkListNode(void*, void*);
extern "C" void fn_801C0A68(void*, void*);

struct Manager {
    s32 pad[0x4A];
    void* size;
    s32 pad2[2];
    void* field134;
};

class Object {
public:
    virtual void f1(int);
    s32 pad[3];
    Manager* manager;
    s32 pad2[6];
    void* node_prev;
    void* node_next;
};

extern "C" void fn_801CF4E0(Object* self) {
    s32 state = OSDisableInterrupts();
    Erase__Q44nw4r2ut6detail12LinkListImplFPQ34nw4r2ut12LinkListNode(
        &self->manager->size, &self->node_prev);
    void* addr = &self->manager->field134;
    if (self) {
        self->f1(-1);
        fn_801C0A68(addr, self);
    }
    OSRestoreInterrupts(state);
}
