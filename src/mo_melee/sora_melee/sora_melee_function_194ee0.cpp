#pragma force_active on
typedef unsigned int u32;

class soModuleAccesser;

extern "C" float getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(soModuleAccesser* accesser, u32 id, u32 index);

struct Constants {
    float unk00[4];
    float unk10;
    float unk14[5];
    float unk28;
    float unk2c;
};

extern const unsigned char lbl_27_rodata_26B0[];

extern "C" float fn_27_194EE0() {
    const Constants* c = (const Constants*)lbl_27_rodata_26B0;
    soModuleAccesser* accesser;
    float x = getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(accesser, 0xbe1, 0);
    float a = c->unk28 * x;
    return c->unk2c - (c->unk2c * a) / (c->unk10 + a);
}
