#pragma force_active on

typedef unsigned char u8;
typedef unsigned int u32;
typedef int s32;
typedef float f32;

extern "C" void* __dynamic_cast(void*, long, const void*, const void*, short);
extern "C" void* getInstance__15gfTaskSchedulerFv();
extern "C" void* getTaskById__15gfTaskSchedulerFQ26gfTask8CategoryUl(void*, int, u32);
extern "C" char lbl_27_data_248[];
extern "C" char __RTTI__6gfTask[];
extern "C" void* fn_27_8CD74(void*);

class soNullable {
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
    virtual void s16(int, int);
    virtual void s17();
    virtual void s18();
    virtual void s19();
    virtual void s20();
    virtual void s21();
    virtual void s22();
    virtual f32 s23(int);
    virtual f32 s24(int);
    virtual f32 s25(int);
    virtual f32 s26(int);
    virtual void s27();
    virtual void s28();
    virtual void* s29();
    virtual void s30();
    virtual void s31();
    virtual void s32();
    virtual void s33();
    virtual void s34();
    virtual void s35();
    virtual void s36();
    virtual void s37();
    virtual void s38();
    virtual void s39();
    virtual void s40();
    virtual void s41();
    virtual void s42();
    virtual void s43();
    virtual void s44();
    virtual void s45();
    virtual void s46();
    virtual void s47();
    virtual void s48();
    virtual void s49();
    virtual void s50();
    virtual void s51();
    virtual void s52();
    virtual void s53();
    virtual void s54();
    virtual void s55();
    virtual void s56();
    virtual void s57();
    virtual void s58();
    virtual void s59();
    virtual void s60();
    virtual void s61();
    virtual void s62();
    virtual void s63();
    virtual void s64();
    virtual void s65();
    virtual void s66();
    virtual void s67(void*, int);
};

struct Arg2;

struct Fd8Obj {
    char pad[0x1C];
    soNullable* n1c;
    char pad2[0x24];
    soNullable* n44;
};

struct Arg2 {
    char pad[0xD8];
    Fd8Obj* fd8;
};

struct Arg1 {
    char pad[0x0C];
    s32 f0c;
    char pad2[0x11];
    u8 f21;
    u8 f22;
    u8 f23;
};

struct SelfBase {
    char pad[8];
};

class Self : public SelfBase {
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
    virtual s32 s15(Arg2*);

    char pad_data[0x18];
    s32 f24;
    void* f28;
    f32 f2c;
    f32 f30;
    f32 f34;
    s32 f38;
    char pad3[1];
    u8 f3d;
};

extern "C" void fn_27_640AC(Self* self, const Arg1* arg1, Arg2* arg2, f32 f) {
    if (arg1->f21 == 3) {
        if ((u32)self->f24 + 0x10000 == 0xFFFF) {
            void* task = getTaskById__15gfTaskSchedulerFQ26gfTask8CategoryUl(
                getInstance__15gfTaskSchedulerFv(), (int)arg1->f22,
                (u32)arg1->f0c);
            void* casted = __dynamic_cast(
                task, 0x3C, lbl_27_data_248, __RTTI__6gfTask, 0);
            soNullable* obj = (soNullable*)fn_27_8CD74(casted);

            if (f < obj->s26((int)arg1->f23)) {
                if (self->s15(arg2) == 0) {
                    self->f24 = arg1->f0c;
                    self->f28 = obj->s29();
                    self->f2c = self->f2c * obj->s23((int)arg1->f23);
                    if (self->f3d == 0) {
                        self->f30 = obj->s24((int)arg1->f23);
                    }
                    self->f34 = obj->s25((int)arg1->f23);
                } else {
                    arg2->fd8->n1c->s67((void*)arg1, 0);
                }
            } else {
                arg2->fd8->n44->s16(1, 0);
                arg2->fd8->n1c->s67((void*)arg1, 0);
            }

            self->f38++;
        }
    }
}
