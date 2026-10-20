#include <types.h>
#pragma force_active on

struct IValueMod {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual s32 getValue(u32);
};

struct IPosture {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual float getLR();
};

extern "C" {
void* fn_41_473DC(void*, s32);
void fn_41_47470(void*, void*, void*);
void fn_41_47544(u8*, void*);
void fn_41_47A2C(void*, void*, u32);
int fn_41_3BE4(void*);
void* __dynamic_cast(void*, long, const void*, const void*, short);
extern char __RTTI__5Enemy[], __RTTI__11StageObject[];
extern u8 lbl_41_bss_504[];

float getValueFloat__15soValueAccesserFP16soModuleAccesserUlUl(
    void*, unsigned long, unsigned long);
int getTeamNo__23soExternalValueAccesserFP11StageObject(void*);

void fn_41_3091C(
    void*, void*, u32, int, int, u8, void*, float, int, float,
    int, u32, short);
void fn_41_47E80(void*, u8, void*, void*, void*);
}

static inline void spawn(
    void* self, void* buf, const u8& flag, void* p, void* acc, int kind)
{
    void* obj = *(void**)((u8*)acc + 8);
    u32 id;
    IPosture* posture =
        *(IPosture**)((u8*)*(void**)((u8*)acc + 0xd8) + 0xc);
    id = *(u32*)((u8*)obj + 0x28);

    fn_41_3091C(
        self, lbl_41_bss_504, id, kind, 0, flag, buf,
        posture->getLR(),
        getTeamNo__23soExternalValueAccesserFP11StageObject(obj),
        *(float*)((u8*)p + 0x14),
        -1,
        (u32)getValueFloat__15soValueAccesserFP16soModuleAccesserUlUl(
            acc, 0x1100000c, 0),
        -1);
}

extern "C" int fn_41_40610(void* self, void* acc)
{
    u32 buf[3];
    u8 flag;
    void* mods = *(void**)((u8*)acc + 0xd8);
    IValueMod* value = *(IValueMod**)((u8*)mods + 0x64);
    void* p = fn_41_473DC(acc, value->getValue(0x10000007));
    void* enemy = __dynamic_cast(
        *(void**)((u8*)acc + 8), 0x3c,
        __RTTI__5Enemy, __RTTI__11StageObject, 1);

    fn_41_47470(buf, p, acc);
    flag = 0;
    fn_41_47544(&flag, p);
    fn_41_47A2C(p, acc, 1);

    if (*(u32*)((u8*)p + 0xc) == 4) {
        int kind = fn_41_3BE4(enemy);
        spawn(self, buf, flag, p, acc, kind);
    } else {
        fn_41_47E80(buf, flag, self, p, acc);
    }
    return 0;
}
