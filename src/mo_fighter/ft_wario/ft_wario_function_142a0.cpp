#include <so/so_module_accesser.h>
#include <so/so_value_accesser.h>
#pragma force_active on

struct V2 { float x; float y; };
extern "C" const float lbl_110_rodata_98;
extern "C" void fn_110_B860(V2* dst, const V2* src);

struct Local {
    unsigned char flag;
    unsigned char pad[3];
    V2 vectors[4];
};

extern "C" void fn_110_142A0(void* unused, void* self, soModuleAccesser* accesser) {
    accesser->getKineticModule().unableEnergyAll();
    soParamAccesser* params = static_cast<soParamAccesser*>(accesser->getWorkManageModule().getParamAccesser());
    float fbc = params->getParamFloat(accesser, 0xfbc, 0);
    float fa3 = params->getParamFloat(accesser, 0xfa3, 0);

    Local local;
    local.flag = 0;
    local.vectors[3].x = lbl_110_rodata_98;
    local.vectors[3].y = lbl_110_rodata_98;
    fn_110_B860((V2*)((char*)self + 0x20), &local.vectors[3]);
    local.vectors[2].x = fbc;
    local.vectors[2].y = lbl_110_rodata_98;
    fn_110_B860((V2*)((char*)self + 0x30), &local.vectors[2]);
    local.vectors[1].x = lbl_110_rodata_98;
    local.vectors[1].y = lbl_110_rodata_98;
    fn_110_B860((V2*)((char*)self + 0x28), &local.vectors[1]);
    local.vectors[0].x = fa3;
    local.vectors[0].y = lbl_110_rodata_98;
    fn_110_B860((V2*)((char*)self + 0x38), &local.vectors[0]);
    *((unsigned char*)self + 0x15) |= 0x80;
}
