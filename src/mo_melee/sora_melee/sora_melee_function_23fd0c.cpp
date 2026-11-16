#include <ec/ec_mgr.h>
#include <gf/gf_3d_scene.h>
#include <gf/gf_task.h>
#include <gm/gm_global.h>
#include <st/st_common_gimmick.h>
#include <types.h>
#pragma force_active on

extern "C" int fn_27_23AC10(void* p);
extern "C" void fn_27_23AC30(void* p);
extern "C" void fn_80060BB8(void* mgr, u32 a, u32 b);
extern void* lbl_8049DEC8;

struct Object_vptr_3c_base { unsigned char pad[0x3c]; };
class Object_vptr_3c : public Object_vptr_3c_base {
public:
    virtual void processDefault();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void processPreMapCorrection();
    virtual void slot5();
    virtual void slot6();
    virtual void processPreCollision();
    virtual void processCollision();
    virtual void processCatch();
    virtual void processHit();
    virtual void processCamera();
    virtual void slot12();
    virtual void processEffect();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void renderOpa();
    virtual void renderXlu();
    virtual void processDebug();
    virtual void slot20();
    virtual void init();
    virtual void slot22();
    virtual void slot23();
    virtual void slot24();
    virtual void slot25();
    virtual void slot26();
    virtual void slot27();
    virtual void slot28();
    virtual void slot29();
    virtual void slot30();
    virtual void slot31();
    virtual void slot32();
    virtual void slot33();
    virtual void slot34();
    virtual void slot35();
    virtual void slot36();
    virtual void slot37();
    virtual void slot38();
    virtual void slot39();
    virtual void slot40();
    virtual void slot41();
    virtual void slot42();
    virtual void slot43();
    virtual void slot44();
    virtual void slot45();
    virtual void slot46();
    virtual void slot47();
    virtual void slot48();
    virtual void slot49();
    virtual void slot50();
    virtual void slot51();
    virtual void slot52();
    virtual void slot53();
    virtual void slot54();
    virtual void slot55();
    virtual void slot56();
    virtual void slot57();
    virtual void slot58();
    virtual void slot59();
    virtual void slot60();
    virtual void slot61();
    virtual void slot62();
    virtual void slot63();
    virtual void slot64();
    virtual void slot65();
    virtual void slot66();
    virtual void slot67();
    virtual void slot68();
    virtual void slot69();
    virtual void slot70();
    virtual void slot71();
    virtual void slot72();
    virtual void slot73();
    virtual void slot74();
    virtual void slot75();
    virtual void slot76();
    virtual void slot77();
    virtual void slot78();
    virtual void slot79();
    virtual void slot80();
    virtual void slot81();
    virtual void slot82();
    virtual void slot83();
    virtual void slot84();
    virtual void slot85();
    virtual void slot86();
    virtual void slot87();
    virtual void slot88();
    virtual void slot89();
    virtual void slot90();
    virtual void slot91();
    virtual Object_vptr_3c* slot92();
};

extern "C" void fn_27_23FD0C(void* self) {
    if (fn_27_23AC10(self)) {
        if (*(stCommonGimmick**)((u8*)self + 0xC4) == 0) {
            return;
        }
        if (*(stCommonGimmick**)((u8*)self + 0xC4)) {
            (*(stCommonGimmick**)((u8*)self + 0xC4))->setPause(false);
            u8* scene = (u8*)g_gfSceneRoot;
            scene[0x464] = scene[0x464] & ~0x2;
            fn_80060BB8(g_ecMgr, 0x02000000, 0xFF000000);
        }
        Object_vptr_3c* r = (*(Object_vptr_3c**)((u8*)self + 0xC4))->slot92();
        if (r) {
            r->slot26();
        }
        ((gfTask*)(*(void**)((u8*)self + 0xC4)))->exit();
        fn_27_23AC30(self);
        *(void**)((u8*)self + 0xC4) = 0;
        g_GameGlobal->m_stageData->m_motionRatio = 1.0f;
        g_GameGlobal->m_stageData->m_motionSubRatio = 1.0f;
        u8* d = (u8*)lbl_8049DEC8;
        if (d) {
            d[0x5C] = 0;
        }
    }
}
