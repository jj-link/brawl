#pragma force_active on
typedef unsigned int u32;

extern "C" float getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(void* accesser, u32 id, u32 index);
extern "C" int getConstantInt__15soValueAccesserFP16soModuleAccesserUlUl(void* accesser, u32 id, u32 index);
extern "C" float randf__Fv();

extern "C" int fn_27_63654(void* self, u32 a, u32 b, float x, float y) {
    if (!(y > getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(self, 0x7df, 0)) ||
        !(y < getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(self, 0x7e0, 0))) {
        if (x >= (float)getConstantInt__15soValueAccesserFP16soModuleAccesserUlUl(self, 0x55f3, 0)) {
            float t = getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(self, 0x7e1, 0);
            if (randf__Fv() < t) {
                return 5;
            }
        }
    }
    return 4;
}
