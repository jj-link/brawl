#pragma force_active on
extern "C" {
float getValueFloat__15soValueAccesserFP16soModuleAccesserUlUl(void*, unsigned long, unsigned long);
float fn_27_60AF4(void*, float, int, int, void*, float, float, float, float, float, int);
}
extern const float lbl_41_rodata_BE4;

struct Self { char pad[0x3c]; void* acc; };
struct P { int a; int b; };

extern "C" float fn_41_FEBC(Self* self, float f1, int a, int b, unsigned d, int e, P* p, float f2) {
    if (d == 1 && a == 0x169) {
        return lbl_41_rodata_BE4 * getValueFloat__15soValueAccesserFP16soModuleAccesserUlUl(self->acc, 0x59dc, 0);
    }
    P v = *p;
    float z;
    float y;
    float x;
    x = getValueFloat__15soValueAccesserFP16soModuleAccesserUlUl(self->acc, 0xbd0, 0);
    y = getValueFloat__15soValueAccesserFP16soModuleAccesserUlUl(self->acc, 0xbd2, 0);
    z = getValueFloat__15soValueAccesserFP16soModuleAccesserUlUl(self->acc, 0xbd1, 0);
    float w = getValueFloat__15soValueAccesserFP16soModuleAccesserUlUl(self->acc, 0xbcf, 0);
    return fn_27_60AF4(self->acc, f1, a, b, &v, f2, w, z, y, x, 1);
}
