#include <gf/gf_task.h>
#include <gf/gf_task_scheduler.h>
#pragma force_active on

extern "C" void* __dynamic_cast(void*, long, const void*, const void*, short);
extern "C" void* fn_27_8CD74(void*);
extern "C" char lbl_27_data_248[];
extern "C" char __RTTI__6gfTask[];

struct Args {
    char pad0[0xC];
    u32 unkC;
    char pad1[0x21 - 0x10];
    u8 unk21;
    u8 unk22;
    u8 unk23;
};

struct Ctx;

class Inner {
public:
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5();
    virtual void s6();
    virtual void s7();
    virtual void s8();
    virtual void s9();
    virtual void s10();
    virtual void s11();
    virtual void s12();
    virtual void s13();
    virtual void s14();
    virtual void s15();
    virtual void s16(const Args* args, int flag);
};

struct Mid {
    char pad[0x34];
    Inner* unk34;
};

struct Ctx {
    char pad[0xD8];
    Mid* unkD8;
};

class Obj {
public:
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5();
    virtual void s6();
    virtual void s7();
    virtual void s8();
    virtual void s9();
    virtual void s10();
    virtual void s11();
    virtual void s12();
    virtual void s13();
    virtual void s14();
    virtual void s15();
    virtual void s16();
    virtual void s17();
    virtual void s18();
    virtual void s19();
    virtual void s20();
    virtual void s21();
    virtual void s22();
    virtual void s23();
    virtual float s24(u8 p);
    virtual float s25(u8 p);
    virtual void s26();
    virtual void s27();
    virtual void s28();
    virtual void* s29();
};

struct Base8 {
    char pad[8];
};

class Self : public Base8 {
public:
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5();
    virtual void s6();
    virtual void s7();
    virtual void s8();
    virtual void s9();
    virtual void s10();
    virtual void s11();
    virtual void s12();
    virtual void s13();
    virtual void s14();
    virtual int s15(Ctx* ctx);
    char pad0[0x24 - 0xC];
    u32 unk24;
    void* unk28;
    char pad1[0x30 - 0x2C];
    float unk30;
    float unk34;
    s32 unk38;
};

extern "C" void fn_27_64290(Self* self, const Args* args, Ctx* ctx) {
    if (args->unk21 == 3 && self->unk24 == -1) {
        if (self->s15(ctx) == 0) {
            void* task = gfTaskScheduler::getInstance()->getTaskById((gfTask::Category)args->unk22, args->unkC);
            void* obj = __dynamic_cast(task, 0x3c, lbl_27_data_248, __RTTI__6gfTask, 0);
            Obj* p = (Obj*)fn_27_8CD74(obj);
            self->unk24 = args->unkC;
            self->unk28 = p->s29();
            self->unk30 = p->s24(args->unk23);
            self->unk34 = p->s25(args->unk23);
        } else {
            ctx->unkD8->unk34->s16(args, 0);
        }
        self->unk38++;
    }
}
