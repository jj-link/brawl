#pragma force_active on

#include <types.h>
#include <gf/gf_task.h>

struct StatusObj {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual int get();
};

struct ObjB {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual u32 get(int);
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual void f17();
    virtual void f18();
    virtual void f19();
    virtual void f20();
    virtual void f21();
    virtual void f22();
    virtual void f23();
    virtual void f24();
    virtual void f25();
    virtual void f26();
    virtual void f27();
    virtual void f28();
    virtual void f29();
    virtual void f30();
    virtual void f31();
    virtual void f32();
    virtual void f33();
    virtual void f34();
    virtual void f35();
    virtual void f36();
    virtual void f37();
    virtual void f38();
    virtual void f39();
    virtual void f40();
    virtual void f41();
    virtual u32 getPtr(int);
};

struct ObjC {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void set(u32, u32);
};

struct Modules {
    char pad0[0x54];
    ObjB* objB;
    char pad1[0xC];
    ObjC* objC;
    char pad2[0x8];
    StatusObj* status;
};

struct Accessor {
    char pad[0xD8];
    Modules* modules;
};

struct Fighter {
    char pad0[0x60];
    Accessor* accessor;
};

struct Event {
    char pad0[0xC];
    u32 taskId;
    char pad1[0x14];
    u8 flag;
};

extern "C" void fn_122_1844C(Fighter* self, Event* arg) {
    if (arg != 0 &&
        (self->accessor->modules->status->get() == 1 ||
         self->accessor->modules->status->get() == 2 ||
         self->accessor->modules->status->get() == 3 ||
         self->accessor->modules->status->get() == 4)) {
        if (self->accessor->modules->objB->get(3) != 1 ||
            arg->taskId != self->accessor->modules->objB->getPtr(3)) {
            gfTask* task = gfTask::getTask(arg->taskId);
            if (task == 0) {
                return;
            }
            switch (task->m_taskCategory) {
            case gfTask::Category_Fighter:
                self->accessor->modules->objC->set(arg->taskId, 0x20000000);
                self->accessor->modules->objC->set(arg->flag, 0x20000001);
                break;
            default:
                break;
            }
        }
    }
}
