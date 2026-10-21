#pragma force_active on
struct Accesser;

extern "C" {
float fn_27_1949F0(Accesser*);
void fn_27_1652A8(void*, float, unsigned long, unsigned long, float, unsigned long, unsigned long);
void fn_27_164BF0(Accesser*, const char*, unsigned long, float, unsigned long);
void fn_107_141A0(void*, void*);
extern const char lbl_107_rodata_78[];
}

extern "C" void* getData__20ftCommonDataAccesserCF6ftKind(const void*, int);
extern "C" char g_ftCommonDataAccesser[];

extern "C" void fn_107_12B2C(void* owner, Accesser* accesser) {
    float* ftData = *(float**)((char*)getData__20ftCommonDataAccesserCF6ftKind(g_ftCommonDataAccesser, 0x12) + 0xb8);
    float a = fn_27_1949F0(accesser);
    fn_27_1652A8(accesser, ftData[2], 0x1f4, 0x21000004, a, 0x21000005, 0);
    fn_27_164BF0(accesser, lbl_107_rodata_78, 0x21000004, a, 0x21000005);
    fn_107_141A0(owner, accesser);
}
