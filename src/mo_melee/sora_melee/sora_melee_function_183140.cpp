#include <so/so_value_accesser.h>
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
    virtual void slot18();
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
extern float lbl_27_rodata_2468;
extern float lbl_27_rodata_246C;
extern "C" void fn_27_183140(void*, soModuleAccesser* a) {
    u8* p = (u8*)a;
    u8* modules = *(u8**)(p + 0xd8);
    Object_vptr_0* work = *(Object_vptr_0**)(modules + 0x64);
    Object_vptr_0* motion = *(Object_vptr_0**)(modules + 8);
    Object_vptr_0* ground = *(Object_vptr_0**)(modules + 0x54);
    float f = (*(Object_vptr_0**)(modules + 0xc))->slot22();
    float g = ground->slot33(0);
    if (g == f) {
        work->slot5(0x18c, 0x20000002);
        work->slot5(0x18f, 0x20000003);
        int offset = 0;
        switch (soValueAccesser::getConstantInt(a, 0x5a98, 0)) {
        case 1: offset = 6; break;
        case 2: offset = 12; break;
        }
        motion->slot99(offset);
    } else {
        work->slot5(-1, 0x20000002);
        work->slot5(-1, 0x20000003);
    }
    motion->slot100(0x1cb);
    int situation = (*(Object_vptr_0**)(*(u8**)(p + 0xd8) + 0x54))->slot39(0);
    int kind;
    if (situation == 0) {
        kind = work->slot4(0x20000002);
    } else {
        kind = work->slot4(0x20000003);
    }
    if (kind != -1) {
        soMotionChangeParam param;
        param.m_kind = kind;
        param.m_frame = lbl_27_rodata_2468;
        param.m_rate = lbl_27_rodata_246C;
        param._12 = 0;
        param._13 = 0;
        param._14 = 0;
        param._15 = 0;
        motion->slot30(&param);
    }
    work->slot5(situation, 0x20000000);
}