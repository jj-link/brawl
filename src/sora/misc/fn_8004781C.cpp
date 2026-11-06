#pragma force_active on

typedef unsigned int u32;
typedef int s32;

class Sub {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
};

class Class_8042B6D0 {
public:
    virtual void fn_8004805C();
    virtual void fn_8004781C();
    virtual void fn_80046A28();
    virtual void fn_8004810C();
    virtual void fn_800480DC();
    virtual void fn_801AB1C4();
    virtual void fn_801B269C();
    virtual void fn_801B26E4();
    virtual void fn_801AAFDC();
    virtual void fn_801AAFE8();
    virtual void fn_801AB290();
    virtual void fn_801B2EEC();
    virtual void fn_801B3050(s32);
    char pad[0xcc - 4];
    u32 mask;
    char pad2[0x138 - 0xd0];
    Sub* sub;
};

extern "C" void fn_801AE2E8(void*, s32, s32);
extern "C" void fn_801AB3C4(void*);
extern "C" void fn_801AF9F4(void*);
extern "C" void fn_801B166C(void*, s32, s32);
extern "C" void fn_801B17E0(void*, s32, s32);
extern "C" void fn_801B1F50(void*, s32, s32);
extern "C" void fn_801B2078(void*, s32, s32);
extern "C" void fn_801B21A0(void*, s32, s32);
extern "C" void fn_80047C2C(void*, s32, s32);

extern "C" void fn_8004781C(Class_8042B6D0* self, u32 arg1, s32 arg2, s32 arg3) {
    s32 var_r0;
    if (arg1 < 9U && ((1U << (arg1 - 1)) & self->mask)) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    if (var_r0 == 0) {
        switch (arg1) {
        case 0x5:
            fn_801AE2E8(self, arg2, arg3);
            break;
        case 0x1:
            fn_801B166C(self, arg2, arg3);
            break;
        case 0x2:
            fn_801B17E0(self, arg2, arg3);
            break;
        case 0x4:
            fn_80047C2C(self, arg2, arg3);
            break;
        case 0x6:
            fn_801B1F50(self, arg2, arg3);
            break;
        case 0x7:
            fn_801B2078(self, arg2, arg3);
            break;
        case 0x8:
            fn_801AF9F4(self);
            if (self->sub != 0) {
                self->sub->f7();
            }
            break;
        case 0x10001:
            self->fn_801B3050(arg3);
            break;
        case 0x3:
            fn_801B21A0(self, arg2, arg3);
            break;
        default:
            fn_801AB3C4(self);
            break;
        }
    }
}
