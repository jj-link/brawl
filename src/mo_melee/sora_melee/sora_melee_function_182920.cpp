#include <so/motion/so_motion_module_impl.h>
#pragma force_active on

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual int slot4(unsigned int);
    virtual void slot5(int, unsigned int);
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual float slot18(int);
    virtual void slot19();
    virtual void slot20();
    virtual void slot21();
    virtual float slot22();
    virtual void slot23();
    virtual void slot24();
    virtual void slot25();
    virtual void slot26();
    virtual void slot27();
    virtual void slot28();
    virtual void slot29();
    virtual void slot30(soMotionChangeParam*);
    virtual void slot31();
    virtual void slot32();
    virtual float slot33(int);
    virtual void slot34();
    virtual void slot35();
    virtual void slot36();
    virtual void slot37();
    virtual void slot38();
    virtual int slot39(int);
    virtual void slot40();
    virtual void slot41();
    virtual void slot42();
    virtual void slot43();
    virtual void slot44();
    virtual void slot45();
    virtual void slot46();
    virtual void slot47();
    virtual void slot48(int, int, int, int, float, float, float);
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
    virtual void slot92();
    virtual void slot93();
    virtual void slot94();
    virtual void slot95();
    virtual void slot96();
    virtual void slot97();
    virtual void slot98();
    virtual void slot99(int);
    virtual void slot100(int);
};

class Dmg { public: char pad[8];
    virtual void d0(); virtual void d1(); virtual void d2(); virtual void d3();
    virtual void d4(); virtual void d5(); virtual void d6(); virtual void d7();
    virtual void d8(); virtual void d9(); virtual void d10(); virtual void d11();
    virtual void d12(); virtual void d13(); virtual void d14(); virtual void d15();
    virtual void d16(); virtual void d17(); virtual float damage(int); };

typedef Object_vptr_0 M;

extern "C" float getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(void*, unsigned int, unsigned int);
extern "C" int getConstantInt__15soValueAccesserFP16soModuleAccesserUlUl(void*, unsigned int, unsigned int);
extern float lbl_27_rodata_2460;
extern float lbl_27_rodata_2464;

#define MOD(o, off) (*(M**)(*(u8**)((u8*)(o) + 0xd8) + (off)))

extern "C" void fn_27_182920(void*, void* p) {
    float a = getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(p, 0xd2f, 0);
    float b = (*(Dmg**)(*(u8**)((u8*)p + 0xd8) + 0x38))->damage(0);
    b *= getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(p, 0xd30, 0);
    M* ctrl = MOD(p, 0x5c);
    float c = getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(p, 0xd31, 0);
    ctrl->slot48(0, -1, 0, 0, a + b, lbl_27_rodata_2460, c);

    u8* modules = *(u8**)((u8*)p + 0xd8);
    M* work = *(M**)(modules + 0x64);
    M* motion = *(M**)(modules + 0x8);
    M* ground = *(M**)(modules + 0x54);
    float f = (*(M**)(modules + 0xc))->slot22();
    float g = ground->slot33(0);
    if (g == f) {
        work->slot5(0x18b, 0x20000002);
        work->slot5(0x18e, 0x20000003);
        int r = 0;
        switch (getConstantInt__15soValueAccesserFP16soModuleAccesserUlUl(p, 0x5a98, 0)) {
        case 1: r = 6; break;
        case 2: r = 12; break;
        }
        motion->slot99(r);
    } else {
        work->slot5(-1, 0x20000002);
        work->slot5(-1, 0x20000003);
    }
    motion->slot100(0x1cb);
    int situation = MOD(p, 0x54)->slot39(0);
    int kind;
    if (situation == 0) {
        kind = work->slot4(0x20000002);
    } else {
        kind = work->slot4(0x20000003);
    }
    if (kind != -1) {
        soMotionChangeParam param;
        param.m_kind = kind;
        param.m_frame = lbl_27_rodata_2464;
        param.m_rate = lbl_27_rodata_2460;
        param._12 = 0;
        param._13 = 1;
        param._14 = 0;
        param._15 = 0;
        motion->slot30(&param);
    }
    work->slot5(situation, 0x20000000);
}
