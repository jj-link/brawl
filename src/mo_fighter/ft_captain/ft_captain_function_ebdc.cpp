#include <so/so_module_accesser.h>
#include <gf/gf_3d_scene.h>
#pragma force_active on

struct soWorld {
    unsigned char pad[0xd];
    unsigned char m_flag;
};

namespace {
struct Cam88 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
    virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
    virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18();
    virtual void m19(int, int);
    virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void m24(int, bool, bool);
};

struct WorkMod {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
    virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
    virtual void v15(); virtual void v16(); virtual void v17();
    virtual void offFlag(unsigned int);
};

struct CapModules {
    unsigned char pad[0x64];
    WorkMod* work;
    unsigned char pad1[0x20];
    Cam88* cam;
};

struct CapAcc {
    unsigned char pad[0xD8];
    CapModules* m_modules;
};
}

extern "C" {
extern soWorld* g_soWorld;
int fn_100_10794(void*, int);
void fn_100_FF9C(int);
void fn_100_FF50();
void fn_100_10288();
void fn_100_1046C();
void fn_100_10518(void*, int);
void fn_100_10B74(void*);
void fn_100_10A4C(void*);
void fn_100_FC20(void*);
void fn_100_FCE0();
void fn_100_10774();
void fn_100_F7F4();
void fn_100_10C78(bool);
void fn_100_10CEC(void*);
}

extern "C" void fn_100_EBDC(void* unused, CapAcc* self, int eventKind) {
    (void)unused;
    fn_100_FF9C(1);
    fn_100_FF50();
    bool on = true;
    self->m_modules->cam->m24(8, on, on);
    self->m_modules->cam->m19(0x48, 8);
    self->m_modules->work->offFlag(0x12000019);
    g_soWorld->m_flag = 1;
    fn_100_10C78(true);
    fn_100_10CEC(0);
    if (fn_100_10794(self, eventKind) == 0) {
        fn_100_10288();
        fn_100_1046C();
        fn_100_10518(self, 0);
        fn_100_10B74(self);
        fn_100_10A4C(self);
        fn_100_FC20(self);
        fn_100_FCE0();
        fn_100_10774();
        fn_100_F7F4();
    }
}