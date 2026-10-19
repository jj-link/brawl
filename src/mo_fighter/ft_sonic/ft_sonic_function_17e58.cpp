#pragma force_active on
struct SonicEnergy {
    unsigned char pad[0x55];
    unsigned char flags;
    unsigned char pad56[2];
    float value58;
    float value5C;
    float value60;
};

struct soModuleAccesser;

extern "C" {
void fn_123_17BB4(SonicEnergy*, soModuleAccesser*);
float getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(
    soModuleAccesser*, unsigned long, unsigned long);

extern const float lbl_123_rodata_9C;
extern const float lbl_123_rodata_98;

void fn_123_17E58(void*, SonicEnergy* energy, soModuleAccesser* accesser) {
    fn_123_17BB4(energy, accesser);

    struct LocalFlag {
        bool value;
    };
    LocalFlag unused = { false };

    energy->value58 =
        getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(
            accesser, 0xFA7, 0);
    energy->value5C = lbl_123_rodata_9C;
    energy->value60 = lbl_123_rodata_98;
    energy->flags |= 0x80;
}
}
