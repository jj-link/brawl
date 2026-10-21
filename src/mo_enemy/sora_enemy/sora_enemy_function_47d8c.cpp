#pragma force_active on

typedef unsigned int u32;

struct Posture {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual float getLR();
};

extern "C" {
void* __dynamic_cast(void*, long, const void*, const void*, short);
extern char __RTTI__5Enemy[];
extern char __RTTI__11StageObject[];
extern char lbl_41_bss_504[];

float getValueFloat__15soValueAccesserFP16soModuleAccesserUlUl(
    void*, unsigned long, unsigned long);
u32 fn_41_AA74(void*, u32);
int getTeamNo__23soExternalValueAccesserFP11StageObject(void*);
void fn_41_2D2A0(
    void*, void*, float, int, int, u32, u32, void*, float, u32, u32);
}

extern "C" void fn_41_47D8C(
    void* arg0, u32 arg1, void* arg2, char* arg3, char* acc)
{
    void* enemy = __dynamic_cast(
        *(void**)(acc + 8), 0x3c,
        __RTTI__5Enemy, __RTTI__11StageObject, 1);
    void* object = *(void**)(acc + 8);
    u32 id = *(u32*)((char*)object + 0x28);
    Posture* posture =
        *(Posture**)(*(char**)(acc + 0xd8) + 0xc);

    fn_41_2D2A0(
        arg2, arg0, posture->getLR(),
        getTeamNo__23soExternalValueAccesserFP11StageObject(object),
        -1, id, fn_41_AA74(enemy, *(u32*)(arg3 + 4)),
        lbl_41_bss_504, *(float*)(arg3 + 0x14), arg1,
        (u32)getValueFloat__15soValueAccesserFP16soModuleAccesserUlUl(
            acc, 0x1100000c, 0));
}
