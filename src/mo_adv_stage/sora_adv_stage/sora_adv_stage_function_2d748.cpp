#pragma force_active on
#include <types.h>

extern "C" char lbl_40_data_B000[];

extern "C" void startMove__19grGimmickMotionPathFv(void* self);
extern "C" void setUpdateRate__16gfModelAnimationFf(void* self, float rate);
extern "C" int getEntryId__9ftManagerFi(void* self, int a);
extern "C" void* getFighter__9ftManagerFii(void* self, int a, int b);
extern "C" int getTeamNo__23soExternalValueAccesserFP11StageObject(void* self);
extern "C" u32 fn_27_8CB9C(void* self);
extern "C" void setTeamYakumono__10grYakumonoFUlUl(void* self, u32 a, u32 b);
extern "C" void getNodeIndex__6GroundFPUlUlPCc(void* self, u32* out, u32 mdl, const char* name);
extern "C" void setAttackGimmick__10grYakumonoFiiUlPQ29grGimmick10AttackDataPQ29grGimmick13AttackDetails(void* self, int a, int b, u32 c, void* d, void* e);
extern "C" void startGimmickSE__9grGimmickFUl(void* self, u32 index);
extern "C" void startGimmickEffect__9grGimmickFUl(void* self, u32 index);
extern "C" void setTriggerFlag__12stTriggerMngFP13stTriggerData(void* self, void* triggerData);
extern "C" void* g_ftManager;
extern "C" void* g_stTriggerMng;

struct Base0 { char pad[0x3c]; };
struct Target : Base0 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual void m8();
    virtual void m9();
    virtual void m10();
    virtual void m11();
    virtual void m12();
    virtual void m13();
    virtual void m14();
    virtual void m15();
    virtual void m16();
    virtual void m17();
    virtual void m18();
    virtual void m19();
    virtual void m20();
    virtual void m21();
    virtual void m22();
    virtual void m23();
    virtual void m24();
    virtual void m25();
    virtual void m26();
    virtual void m27();
    virtual void m28();
    virtual void m29();
    virtual void m30();
    virtual void m31();
    virtual void m32();
    virtual void m33();
    virtual void m34();
    virtual void m35();
    virtual void m36();
    virtual void m37();
    virtual void m38();
    virtual void m39();
    virtual void m40();
    virtual void m41();
    virtual void m42();
    virtual void m43();
    virtual void m44();
    virtual void m45();
    virtual void m46();
    virtual void m47();
    virtual void m48();
    virtual void m49();
    virtual void m50();
    virtual void m51();
    virtual void m52();
    virtual void m53();
    virtual void m54();
    virtual void m55();
    virtual void m56();
    virtual void m57();
    virtual void m58();
    virtual void m59();
    virtual void m60();
    virtual void m61();
    virtual void m62();
    virtual void m63();
    virtual void m64();
    virtual void m65();
    virtual void m66();
    virtual void m67();
    virtual void m68();
    virtual void m69();
    virtual void m70();
    virtual void m71();
    virtual void m72();
    virtual void m73();
    virtual void m74();
    virtual void m75();
    virtual void m76();
    virtual void m77();
    virtual void m78();
    virtual void m79();
    virtual void m80();
    virtual void m81();
    virtual void change(u32 a, u32 b);  // slot offset 0x150
};

extern "C" void fn_40_2D748(void* self) {
    char* p = (char*)self;
    startMove__19grGimmickMotionPathFv(*(void**)(p + 0xcc));

    ((Target*)self)->change(0, 0);

    setUpdateRate__16gfModelAnimationFf(*(void**)(*(void**)(p + 0x48)), *(float*)(*(void**)(p + 0x150)));

    int entry = getEntryId__9ftManagerFi(g_ftManager, 0);
    void* fighter = getFighter__9ftManagerFii(g_ftManager, entry, -1);
    if (fighter != NULL) {
        u32 team = getTeamNo__23soExternalValueAccesserFP11StageObject(fighter);
        u32 owner = fn_27_8CB9C(fighter);
        setTeamYakumono__10grYakumonoFUlUl(self, team, owner);
    }

    u32 node = 0;
    getNodeIndex__6GroundFPUlUlPCc(self, &node, 0, lbl_40_data_B000);

    setAttackGimmick__10grYakumonoFiiUlPQ29grGimmick10AttackDataPQ29grGimmick13AttackDetails(self, 0, 0, node, (void*)((char*)(*(void**)(p + 0x150)) + 0x1ec), NULL);

    startGimmickSE__9grGimmickFUl(self, 1);
    startGimmickSE__9grGimmickFUl(self, 2);
    startGimmickSE__9grGimmickFUl(self, 3);
    startGimmickSE__9grGimmickFUl(self, 4);
    startGimmickSE__9grGimmickFUl(self, 5);
    startGimmickSE__9grGimmickFUl(self, 6);
    startGimmickSE__9grGimmickFUl(self, 7);
    startGimmickSE__9grGimmickFUl(self, 0xa);
    startGimmickEffect__9grGimmickFUl(self, 0);
    startGimmickEffect__9grGimmickFUl(self, 1);
    startGimmickEffect__9grGimmickFUl(self, 2);
    startGimmickEffect__9grGimmickFUl(self, 3);
    startGimmickEffect__9grGimmickFUl(self, 4);

    setTriggerFlag__12stTriggerMngFP13stTriggerData(g_stTriggerMng, (void*)((char*)(*(void**)(p + 0x150)) + 0x270));
}
