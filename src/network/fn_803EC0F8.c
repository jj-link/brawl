#pragma force_active on
typedef signed char s8;

int fn_803EB948(s8);

int fn_803EC0F8(s8 arg0) {
    int v0;
    v0 = fn_803EB948(arg0);
    return (-v0 | v0) >> 0x1F;
}
