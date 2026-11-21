#pragma opt_common_subs off
#pragma opt_deadcode off
#pragma opt_propagation off
#pragma opt_dead_assignments off

#include <so/so_module_accesser.h>
#include <so/so_value_accesser.h>
#pragma force_active on

struct DiddySpeed {
    float x;
    float y;
};

class DiddySpeedEnergy : public soNullable, public soEnable, public soSuspendable {
public:
    virtual void updateEnergy(soModuleAccesser*);
    virtual DiddySpeed getSpeed();
    void enable() { reinterpret_cast<unsigned char*>(this)[5] |= 0x80; }
};

extern "C" {
extern const float lbl_115_rodata_E8;
void fn_115_C8BC(float* dst, const float* src);
}

extern "C" void fn_115_13104(s32 arg0, const DiddySpeed* arg1,
                             unsigned char* arg2, soModuleAccesser* arg3) {
    DiddySpeedEnergy* energy;
    soParamAccesser* params;
    s32 kind = arg0;
    const DiddySpeed* input = arg1;
    unsigned char* energies = arg2;
    soModuleAccesser* accesser = arg3;
    params = static_cast<soParamAccesser*>(accesser->getWorkManageModule().getParamAccesser());
    switch (kind) {
    case 0:
        break;
    case 1: {
        DiddySpeed speed = {lbl_115_rodata_E8, lbl_115_rodata_E8};
        DiddySpeed accel = {lbl_115_rodata_E8, lbl_115_rodata_E8};
        speed.x = input->x;
        speed.y += input->y;
        accel.x = params->getParamFloat(accesser, 0xfa9, 0);
        if (lbl_115_rodata_E8 != speed.x || lbl_115_rodata_E8 != speed.y) {
            bool flag = false;
            bool* flagPtr = &flag;
            (void)flagPtr;
            *reinterpret_cast<float*>(energies + 0x120) += speed.x;
            *reinterpret_cast<float*>(energies + 0x124) += speed.y;
            *reinterpret_cast<float*>(energies + 0x128) = params->getParamFloat(accesser, 0xfa8, 0);
            fn_115_C8BC(reinterpret_cast<float*>(energies + 0x10c), &accel.x);
            energies[0xf1] |= 0x80;
        }
        break;
    }
    case 2: {
        DiddySpeed speed = {lbl_115_rodata_E8, lbl_115_rodata_E8};
        switch (accesser->getSituationModule().getKind()) {
        case 0:
            speed.x = input->x;
            break;
        case 2:
        case 3:
            speed.x = input->x;
            speed.y = input->y;
            break;
        }
        if (lbl_115_rodata_E8 != speed.x) {
            bool flag = false;
            bool* flagPtr = &flag;
            (void)flagPtr;
            energy = reinterpret_cast<DiddySpeedEnergy*>(energies + 0x10);
            DiddySpeed ns;
            DiddySpeed cur = energy->getSpeed();
            ns.x = input->x + cur.x;
            ns.y = lbl_115_rodata_E8;
            fn_115_C8BC(reinterpret_cast<float*>(reinterpret_cast<unsigned char*>(energy) + 8), &ns.x);
            energy->enable();
        }
        if (lbl_115_rodata_E8 != speed.y) {
            bool flag = false;
            bool* flagPtr = &flag;
            (void)flagPtr;
            energy = reinterpret_cast<DiddySpeedEnergy*>(energies + 0x50);
            DiddySpeed cur = energy->getSpeed();
            *reinterpret_cast<float*>(reinterpret_cast<unsigned char*>(energy) + 8) = speed.y + cur.y;
            energy->enable();
        }
        break;
    }
    }
}
