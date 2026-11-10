#include <types.h>
#pragma force_active on

class VT {
public:
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void* s5();
    virtual void s6();
    virtual void s7();
    virtual void s8();
    virtual void s9();
    virtual void s10();
    virtual void s11();
    virtual void* s12(u8, void*);
    virtual void s13();
    virtual void s14();
    virtual void s15();
    virtual void s16();
    virtual void s17();
    virtual void s18(int, u32, int);
};

struct Result {
    char pad0[0x10];
    u32 w10;
    u32 w14;
};

struct Mid {
    char pad0[0x30];
    VT* a30;
    char pad1[0x40 - 0x34];
    VT* a40;
};

struct Owner {
    char pad0[8];
    int unk8;
    char pad1[0xd8 - 0xc];
    Mid* mid;
};

struct Self {
    char pad0[0x10];
    Owner* owner;
    char pad1[0x30 - 0x14];
    u32 taskId;
    char pad2[0x46 - 0x34];
    u8 cat;
    char pad3[0x49 - 0x47];
    u8 flag;
};

extern "C" {
void* getInstance__15gfTaskSchedulerFv();
void* getTaskById__15gfTaskSchedulerFQ26gfTask8CategoryUl(void* sched, int cat, u32 id);
void* __dynamic_cast(void*, long, const void*, const void*, short);
VT* fn_27_8CDB4();
}
extern "C" char lbl_27_data_248[];
extern "C" char __RTTI__6gfTask[];

extern "C" void fn_27_65AE0(Self* self) {
    Owner* owner = self->owner;
    if (owner->mid->a40->s5() == 0) {
        void* task = getTaskById__15gfTaskSchedulerFQ26gfTask8CategoryUl(getInstance__15gfTaskSchedulerFv(), self->cat, self->taskId);
        __dynamic_cast(task, 0x3c, lbl_27_data_248, __RTTI__6gfTask, 0);
        VT* r31 = fn_27_8CDB4();
        Result* p = (Result*)self->owner->mid->a30->s12(self->flag, self->owner);
        r31->s18(self->owner->unk8, (p->w10 >> 14) & 0x1FF, (p->w14 >> 25) & 1);
    }
}
