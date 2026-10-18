#pragma force_active on
struct Pair {
    float a;
    float b;
};

extern "C" const float lbl_115_rodata_F0;

extern "C" void fn_115_17168(char *base) {
    Pair *p = (Pair *)(base + 8);
    p->b = lbl_115_rodata_F0;
    p->a = lbl_115_rodata_F0;
}
