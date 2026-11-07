#include <types.h>
#include <nw4r/ut/ut_LinkList.h>
#include <revolution/OS/OSInterrupt.h>
#pragma force_active on

class List : public nw4r::ut::detail::LinkListImpl {
public:
    using nw4r::ut::detail::LinkListImpl::Erase;
};
struct Manager {
    char pad[0xbc];
    u8 flag;
    char pad2[0x128 - 0xbd];
    List list;
    char field134;
};
class Class_80466C80 {
public:
    virtual void fn_801CD318(int);
    char pad[0xc];
    Manager* manager;
    int a, b, c, d, e;
    u8 f;
    char pad2[3];
    nw4r::ut::LinkListNode node;
};
class Object_vptr_0 {
public:
    virtual void slot0();
};
extern "C" int fn_801CDEA0(Manager*, int, int, int, int, int, u8);
extern "C" void fn_801C0A68(void*, void*);
extern "C" void fn_801CF420(Class_80466C80* self) {
    if (!fn_801CDEA0(self->manager, self->a, self->c, self->b, self->d, self->e, self->f))
        self->manager->flag = 1;
    BOOL state = OSDisableInterrupts();
    self->manager->list.Erase(&self->node);
    void* addr = &self->manager->field134;
    if (self) {
        self->fn_801CD318(-1);
        fn_801C0A68(addr, self);
    }
    OSRestoreInterrupts(state);
}