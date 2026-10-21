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
void fn_41_25524(void*, void*, unsigned long, int);

extern float lbl_41_rodata_D54;
extern float lbl_41_rodata_D58;

float fn_41_2619C(void*, unsigned long);
float fn_41_262E8(void*, unsigned long);
V2 fn_41_24278(V2, float, float, float);
void fn_41_25138(void*, const V3&, V2, V2);

void fn_41_25A50(void* acc, unsigned long target, V2* first,
                 const V2* second, unsigned long mode) {
    V3 pos;
    fn_41_25524(&pos, acc, target, 1);

    float scale = lbl_41_rodata_D54;
    if (mode == 1)
        scale = fn_41_2619C(acc, target);

    *first = fn_41_24278(
        *first, scale, fn_41_262E8(acc, target), lbl_41_rodata_D58);

    fn_41_25138(acc, pos, *first, *second);
}
}
