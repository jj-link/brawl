#pragma force_active on

struct V2 {
    float x, y;

    V2& operator=(const V2& v) {
        x = v.x;
        y = v.y;
        return *this;
    }
};

struct V3 {
    float x, y, z;
};

extern "C" {
void getTargetPos__16emAreaModuleImplFP16soModuleAccesserUlb(
    V3*, void*, unsigned long, bool);

extern float lbl_41_rodata_D54;
extern float lbl_41_rodata_D58;

float fn_41_23CD4(void*, unsigned long);
float fn_41_23E0C(void*, unsigned long);
V2 fn_41_24278(V2, float, float, float);
void fn_41_23F3C(void*, const V3&, V2, V2, float, float);

void fn_41_24144(void* acc, unsigned long target, V2* first,
                 const V2* second, float farg0, float farg1, unsigned long mode) {
    V3 pos;
    getTargetPos__16emAreaModuleImplFP16soModuleAccesserUlb(
        &pos, acc, target, true);

    float scale = lbl_41_rodata_D54;
    if (mode == 1)
        scale = fn_41_23CD4(acc, target);

    *first = fn_41_24278(
        *first, scale, fn_41_23E0C(acc, target), lbl_41_rodata_D58);

    fn_41_23F3C(acc, pos, *first, *second, farg0, farg1);
}
}
