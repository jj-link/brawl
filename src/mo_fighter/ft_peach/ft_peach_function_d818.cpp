#pragma force_active on
extern "C" void fn_27_15FBC8(int);
extern "C" float getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(
    void*, unsigned long, unsigned long);

struct Energy {
    unsigned char padding[0x50];
    float value;
};

extern "C" void fn_103_D818(void*, Energy* energy, const void*, void* accesser) {
    fn_27_15FBC8(18);
    bool flag[1] = {false};
    energy->value =
        getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(
            accesser, 0xfb6, 0);
}
