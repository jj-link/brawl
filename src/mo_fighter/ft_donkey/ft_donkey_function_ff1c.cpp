#pragma force_active on
struct Accesser;

extern "C" {
float fn_27_1949F0(Accesser*);
float getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(Accesser*, unsigned long, unsigned long);
void fn_27_1652A8(Accesser*, unsigned long, unsigned long, float, float, unsigned long, unsigned long);
extern const char lbl_92_rodata_90[];
void fn_27_164BF0(Accesser*, const char*, unsigned long, float, unsigned long);
}

extern "C" void fn_92_FF1C(void*, Accesser* accesser) {
    float a = fn_27_1949F0(accesser);
    float e = getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(accesser, 0xbbb, 0);
    fn_27_1652A8(accesser, 0x1da, 0x21000004, e, a, 0x21000005, 0);
    fn_27_164BF0(accesser, lbl_92_rodata_90, 0x21000004, a, 0x21000005);
}
