#include <types.h>
#pragma force_active on

struct ScnMdl {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13(void* p);
    virtual void v14(void* p);
    virtual void v15(void* p);
};

struct GameSub {
    char pad[4];
    u8 kind;
};

struct GameGlobal {
    char pad[0x10];
    GameSub* sub;
};

extern "C" {
extern GameGlobal* g_GameGlobal;
extern char lbl_10_data_734[];
extern char lbl_10_data_73C[];
void setFrameVisible__8MuObjectFf(void* obj, float f);
void Pushback__Q34nw4r3g3d6ScnMdlFPvPvPc(ScnMdl* mdl, void* a, char* b);
}

extern "C" void fn_10_10398(char* self, s32 arg1) {
    char* obj = *(char**)(self + 0x400);
    ScnMdl* mdl;
    char* name;
    if ((s32)g_GameGlobal->sub->kind == 7) {
        mdl = *(ScnMdl**)(self + 0x508);
        name = lbl_10_data_734;
    } else {
        mdl = *(ScnMdl**)(self + 0x500);
        name = lbl_10_data_73C;
    }
    mdl->v13(*(void**)(obj + 0x10));
    if (arg1 >= 0) {
        setFrameVisible__8MuObjectFf(obj, (f32)(arg1 + 1));
        Pushback__Q34nw4r3g3d6ScnMdlFPvPvPc(mdl, *(void**)(obj + 0x10), name);
    }
}
