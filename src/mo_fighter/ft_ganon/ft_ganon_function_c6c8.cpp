#include <so/so_module_accesser.h>
#include <so/so_value_accesser.h>
#include <so/status/so_status_module_impl.h>
#include <so/work/so_work_manage_module_impl.h>
#pragma force_active on

struct GanStopEnergyView : soKineticEnergy {
    Vec2f speed;
};

struct GanA { virtual void v0(); virtual void v1(); virtual void v2(); virtual int v3(); };
struct GanB { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(int); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(int); };

extern "C" {
extern const char lbl_109_data_657C[], lbl_109_data_1670[];
void* __dynamic_cast(void*, long, const void*, const void*, short);
}

extern "C" void fn_109_C6C8(void*, soModuleAccesser* accesser, int kind) {
    switch (kind) {
    case 0x118: {
        GanStopEnergyView* stop = static_cast<GanStopEnergyView*>(__dynamic_cast(
            accesser->getKineticModule().getEnergy(0), 0,
            lbl_109_data_657C, lbl_109_data_1670, 1));
        Vec2f speed;
        Vec2f::copy(speed, stop->getSpeed());
        float m = soValueAccesser::getConstantFloat(accesser, 0xfa5, 0);
        stop->speed = speed * m;
        break;
    }
    case 0x119:
        break;
    default: {
        char* en = *(char**)((char*)accesser + 0xd8);
        if ((*(GanA**)(en + 0x14))->v3() == 2) {
            soValueAccesser::getConstantFloat(accesser, 0xfa8, 0);
            (*(GanB**)(*(char**)((char*)accesser + 0xd8) + 0x64))->v13(0x11000000);
            (*(GanB**)(*(char**)((char*)accesser + 0xd8) + 0x64))->v18(0x12000003);
        }
    }
    }
}
