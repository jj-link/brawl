#include <so/so_module_accesser.h>
#include <so/kinetic/so_kinetic_module_impl.h>
#include <so/situation/so_situation_module_impl.h>
#include <so/work/so_work_manage_module_impl.h>

struct NessResetSpeed { float x; float y; };
// Preserve the original two-register speed return ABI.
class NessResetSpeedView : public soNullable {
public:
    virtual void updateEnergy(soModuleAccesser*);
    virtual NessResetSpeed getSpeed();
};
struct NessAirResetProcess { void* vtable; };
struct NessAirResetRegistration { void* next; void* object; void* destructor; };
extern "C" {
extern NessAirResetProcess lbl_101_bss_23C;
extern NessAirResetRegistration lbl_101_bss_230;
extern unsigned char lbl_101_data_8C70[];
extern const char lbl_101_data_884C[], lbl_101_data_3890[];
void* __dynamic_cast(void*, long, const void*, const void*, short);
void* fn_101_B640(StageObject*);
NessAirResetProcess* fn_101_12C98(NessAirResetProcess*);
void* fn_101_12C10(void*, short);
void __register_global_object(void*, void*, void*);
}

extern "C" void fn_101_12C50() {
    fn_101_12C98(&lbl_101_bss_23C);
    __register_global_object(&lbl_101_bss_23C,
        reinterpret_cast<void*>(fn_101_12C10), &lbl_101_bss_230);
}

#pragma dont_inline on
extern "C" NessAirResetProcess* fn_101_12C98(NessAirResetProcess* process) {
    process->vtable = lbl_101_data_8C70;
    return process;
}
#pragma dont_inline reset

extern "C" void fn_101_12CA8(void*, soModuleAccesser* accesser) {
    if (accesser->getSituationModule().getKind() == 2) {
        soKineticModule& kinetic = accesser->getKineticModule();
        unsigned char* data = *reinterpret_cast<unsigned char**>(
            reinterpret_cast<unsigned char*>(fn_101_B640(&accesser->getStageObject())) + 0xC);
        NessResetSpeedView* energy = static_cast<NessResetSpeedView*>(__dynamic_cast(
            kinetic.getEnergy(3), 0, lbl_101_data_884C, lbl_101_data_3890, 1));
        Vec2f speed;
        NessResetSpeed raw = energy->getSpeed();
        __memcpy(&speed, &raw, sizeof(speed));
        speed.m_x *= *reinterpret_cast<float*>(data + 0xC);
        *reinterpret_cast<float*>(reinterpret_cast<unsigned char*>(energy) + 8) = speed.m_x;
        *reinterpret_cast<float*>(reinterpret_cast<unsigned char*>(energy) + 0xC) = speed.m_y;
        kinetic.getEnergy(1)->clearSpeed();
        kinetic.getEnergy(0)->clearSpeed();
    }
    accesser->getWorkManageModule().setInt(-1, 0x20000002);
    accesser->getWorkManageModule().setInt(-1, 0x20000003);
}

void operator delete(void*);
extern "C" void* fn_101_12E1C(void* object, short deleting) {
    if (object != 0 && deleting > 0) {
        operator delete(object);
    }
    return object;
}

__declspec(section ".ctors") extern void (*const nessAirEnergyResetInitializer)() = fn_101_12C50;
