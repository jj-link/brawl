#include <so/so_module_accesser.h>
#pragma force_active on
struct Prefix { char pad[8]; };
class Physics : public Prefix {
public:
virtual void slot0() = 0;
virtual void slot1() = 0;
virtual void slot2() = 0;
virtual void slot3() = 0;
virtual void slot4() = 0;
virtual void slot5() = 0;
virtual void slot6() = 0;
virtual void slot7() = 0;
virtual void slot8() = 0;
virtual void slot9() = 0;
virtual void slot10() = 0;
virtual void slot11() = 0;
virtual void slot12() = 0;
virtual void slot13() = 0;
virtual void slot14() = 0;
virtual void slot15() = 0;
virtual void slot16() = 0;
virtual void slot17() = 0;
virtual void slot18() = 0;
virtual void slot19() = 0;
virtual void slot20() = 0;
virtual void slot21() = 0;
virtual void slot22() = 0;
virtual void slot23() = 0;
virtual void slot24() = 0;
virtual void slot25() = 0;
virtual int slot70() = 0;
virtual void slot27() = 0;
virtual void slot28() = 0;
virtual void slot29() = 0;
virtual void slot30() = 0;
virtual void slot31() = 0;
virtual void slot32() = 0;
virtual void slot33() = 0;
virtual void slot34() = 0;
virtual void slot35() = 0;
virtual void slot36() = 0;
virtual void slot37() = 0;
virtual void slot38() = 0;
virtual void slotA4(int) = 0;
virtual void slot40() = 0;
virtual void slot41() = 0;
virtual void slotB0(Vec3f*, int, int) = 0;
};
struct CastResult { char pad[0x20e4]; float* data; };
extern "C" {
void* __dynamic_cast(void*, long, const void*, const void*, short);
extern const char lbl_104_data_BEC4[], lbl_104_data_2EDC[];
extern const float lbl_104_rodata_1B0;
}
extern "C" void fn_104_24534(void*, soModuleAccesser* accesser) {
    Physics* physics = static_cast<Physics*>(accesser->m_enumerationStart->m_physicsModule);
    float* data = static_cast<CastResult*>(__dynamic_cast(*reinterpret_cast<void**>(reinterpret_cast<char*>(accesser) + 8), 0x3c, lbl_104_data_BEC4, lbl_104_data_2EDC, 1))->data;
    Vec3f v(lbl_104_rodata_1B0, lbl_104_rodata_1B0, lbl_104_rodata_1B0);
    v.m_x = *data * accesser->getPostureModule().getLr();
    physics->slotB0(&v, physics->slot70(), 7);
    physics->slotA4(0);
}