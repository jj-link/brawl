#include <so/so_value_accesser.h>
#include <nw4r/ut/ut_algorithm.h>
#pragma force_active on
class Class_1250 {
public:
    virtual void fn_27_13C90();
    virtual void fn_27_14068();
    virtual void fn_27_140C0();
    virtual void fn_27_1412C(int, soModuleAccesser*);
    virtual void fn_27_14134();
    virtual void fn_27_14370();
    virtual void* fn_27_14A28(int);
    virtual void fn_27_14A30();
    virtual Vec2f fn_27_14A38(int);
    virtual void fn_27_14A48();
    virtual void fn_27_14A68();
    virtual void fn_27_14AD8();
    virtual void fn_27_14A60();
    virtual void fn_27_14D08();
    virtual void fn_27_14EDC();
    virtual void fn_27_14D00();
    virtual void fn_27_14B80();
    virtual void fn_27_14B88();
    virtual void fn_27_16A70();
    virtual void fn_27_16AB8();
    virtual void fn_27_1CBB4();
    virtual void fn_27_14A20();
    virtual void fn_27_1CBAC();
    virtual void fn_27_1CBA4();
    virtual void fn_27_14B98();
    virtual void fn_27_14B90();
    virtual void fn_27_1CB88();
    virtual void fn_27_14CF8();
    virtual void fn_27_16778();
    virtual void fn_27_1688C();
    virtual void fn_27_1C2E4();
    virtual void fn_27_1BC08();
    virtual void fn_27_1BCF0();
    virtual void fn_27_16AE0();
    virtual void fn_27_15604();
    virtual void fn_27_16CA8();
    virtual void fn_27_16CB0();
    virtual void fn_27_1CB80();
    virtual void fn_27_16CB8();
    virtual void fn_27_16CC0();
    virtual float fn_27_16E88(int);
};
extern "C" void* __dynamic_cast(void*, long, const void*, const void*, short);
extern "C" char lbl_27_data_2E5F8[];
extern "C" char lbl_27_data_CDF8[];
extern "C" void fn_27_17A074(void*, soModuleAccesser* accesser) {
    __dynamic_cast(((Class_1250*)accesser->m_enumerationStart->m_kineticModule)->fn_27_14A28(3),
                   0, lbl_27_data_2E5F8, lbl_27_data_CDF8, 1);
    Vec2f speed;
    Vec2f::copy(speed, ((Class_1250*)accesser->m_enumerationStart->m_captureModule)->fn_27_14A38(0));
    Class_1250* link = (Class_1250*)accesser->m_enumerationStart->m_linkModule;
    float absY;
    if (speed.m_x * link->fn_27_16E88(0) > soValueAccesser::getConstantFloat(accesser, 0xcc0, 0) ||
        (absY = (float)(double)nw4r::ut::Abs(speed.m_y),
         absY > soValueAccesser::getConstantFloat(accesser, 0xcc1, 0))) {
        ((Class_1250*)accesser->m_enumerationStart->m_statusModule)->fn_27_1412C(0x40, accesser);
    }
}
