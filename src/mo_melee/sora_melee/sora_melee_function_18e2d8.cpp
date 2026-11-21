#include <ft/ft_manager.h>
#include <ft/ft_external_value_accesser.h>
#include <so/so_external_value_accesser.h>
#include <types.h>

#pragma force_active on

struct PostureModule {
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void setPosition(Vec3f*);
    virtual void a0();
    virtual void a1();
    virtual void a2();
    virtual void a3();
    virtual void a4();
    virtual void a5();
    virtual void setLr(float);
    virtual void b0();
    virtual void b1();
    virtual void b2();
    virtual void b3();
    virtual void b4();
    virtual void b5();
    virtual void b6();
    virtual void b7();
    virtual void b8();
    virtual void b9();
    virtual void b10();
    virtual float update();
};

struct GroundBase {
    int a;
    int b;
};

struct GroundModule : GroundBase {
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
    virtual void s24();
    virtual void s25();
    virtual void s26();
    virtual void s27();
    virtual void s28();
    virtual void s29();
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
    virtual void s67();
    virtual void s68();
    virtual void s69();
    virtual void s70();
    virtual void s71();
    virtual void s72();
    virtual void s73();
    virtual void s74();
    virtual void s75();
    virtual void s76();
    virtual void s77();
    virtual void s78();
    virtual void s79();
    virtual void s80();
    virtual void s81();
    virtual void s82();
    virtual void s83();
    virtual void s84();
    virtual void s85();
    virtual void s86();
    virtual void s87();
    virtual void s88();
    virtual void s89();
    virtual void s90();
    virtual void s91();
    virtual void s92();
    virtual void s93();
    virtual void s94();
    virtual void s95();
    virtual void s96();
    virtual void s97();
    virtual void s98();
    virtual void s99();
    virtual void s100();
    virtual void s101();
    virtual void s102();
    virtual void s103();
    virtual void s104();
    virtual void s105();
    virtual void s106();
    virtual void setPos(float*, int, float);
};

struct SoundModule {
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void play(int, int, int, int);
};

struct WorkModule {
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual int getInt(int);
};

struct EffectModule {
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5();
    virtual void spawn(int, float*, float*, float, int, int);
    virtual void a0();
    virtual void a1();
    virtual void a2();
    virtual void a3();
    virtual void a4();
    virtual void a5();
    virtual void a6();
    virtual void a7();
    virtual void a8();
    virtual void a9();
    virtual void a10();
    virtual void a11();
    virtual void a12();
    virtual void remove(int);
};

struct Modules {
    char pad0[0x0c];
    PostureModule* posture;
    GroundModule* ground;
    char pad1[0x3c];
    SoundModule* sound;
    char pad2[0x10];
    WorkModule* work;
    char pad3[0x20];
    EffectModule* effect;
};

struct Accesser {
    char pad[0xd8];
    Modules* modules;
};

extern "C" unsigned int fn_27_10A848(ftManager*, int, int);
extern float lbl_27_rodata_25D8;

extern "C" void fn_27_18E2D8(void*, Accesser* accesser) {
    int entry = g_ftManager->getEntryId(0);

    if (g_ftManager->isValidEntryId(entry) == 1 &&
        fn_27_10A848(g_ftManager, entry, -1) == 1) {
        Fighter* fighter = g_ftManager->getFighter(entry, -1);
        Vec3f hipPos = ftExternalValueAccesser::getHipPos(fighter);
        hipPos.m_z = lbl_27_rodata_25D8;

        accesser->modules->posture->setPosition(&hipPos);

        PostureModule* p = accesser->modules->posture;
        p->setLr(soExternalValueAccesser::getLr(fighter));

        float groundPos[2];
        groundPos[0] = hipPos.m_x;
        groundPos[1] = hipPos.m_y;
        accesser->modules->ground->setPos(groundPos, 0, hipPos.m_y);

        float scale = accesser->modules->posture->update();

        Vec3f effectPos;
        Vec3f effectScale;
        float x;
        float y;
        y = hipPos.m_y;
        x = hipPos.m_x;
        effectScale.m_x = lbl_27_rodata_25D8;
        effectScale.m_y = lbl_27_rodata_25D8;
        effectScale.m_z = lbl_27_rodata_25D8;
        effectPos.m_x = x;
        effectPos.m_y = y;
        effectPos.m_z = lbl_27_rodata_25D8;

        accesser->modules->effect->spawn(
            0x1030017, (float*)&effectPos, (float*)&effectScale, scale, 0, -1);
        accesser->modules->sound->play(0x2288, 0, 0, 0);
    }

    int handle = accesser->modules->work->getInt(0x20000000);
    if (handle != 0) {
        accesser->modules->effect->remove(handle);
    }
}