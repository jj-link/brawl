#include <so/motion/so_motion_module_impl.h>
#pragma force_active on

namespace VTables {
class soNullable {
public:
    virtual void isNull();
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
    virtual float slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
    virtual void slot20();
    virtual void slot21();
    virtual void slot22();
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
    virtual void slot33();
    virtual void slot34();
    virtual void slot35();
    virtual void slot36();
    virtual void slot37();
    virtual void slot38();
    virtual int slot39(unsigned int);
};
}

extern float lbl_27_rodata_246C;

extern "C" void fn_27_183394(void*, u8* object) {
    u8* modules = *(u8**)(object + 0xd8);
    VTables::soNullable* work = *(VTables::soNullable**)(modules + 0x64);
    VTables::soNullable* motion = *(VTables::soNullable**)(modules + 8);
    int situation = (*(VTables::soNullable**)(modules + 0x54))->slot39(0);
    if (situation != work->slot4(0x20000000)) {
        int kind;
        if (situation == 0) {
            kind = work->slot4(0x20000002);
        } else {
            kind = work->slot4(0x20000003);
        }
        if (kind != -1) {
            float frame = motion->slot12();
            soMotionChangeParam param;
            param.m_kind = kind;
            param.m_frame = frame;
            param.m_rate = lbl_27_rodata_246C;
            param._12 = 0;
            param._13 = 0;
            param._14 = 1;
            param._15 = 0;
            motion->slot30(&param);
        }
        work->slot5(situation, 0x20000000);
    }
}
