#pragma force_active on
extern "C" {
extern void* g_GameGlobal;
extern const float lbl_2_rodata_DA0;
extern const float lbl_2_rodata_D9C;
extern const double lbl_2_rodata_DA8;
void* fn_8004E5D8(void*, int);

unsigned int fn_2_24F8C(int arg0) {
    float total = lbl_2_rodata_DA0;
    for (int i = 0; i < 35; i++) {
        total += (float)*(unsigned int*)((char*)fn_8004E5D8(g_GameGlobal, i) + 0x68);
    }
    float result = lbl_2_rodata_DA0;
    if (total > result) {
        result = lbl_2_rodata_D9C *
                 (lbl_2_rodata_D9C *
                  ((float)*(unsigned int*)((char*)fn_8004E5D8(g_GameGlobal, arg0) + 0x68) /
                   total));
    }
    return (unsigned int)result;
}
}