#pragma force_active on
extern "C" {
extern void* g_GameGlobal;
void* fn_8004E5D8(void*, void*);
extern const float lbl_2_rodata_D9C;
extern const float lbl_2_rodata_DA0;
}
struct MenuData {
    char pad[0x4C];
    unsigned int numerator;
    unsigned int denominator;
};
extern "C" unsigned int fn_2_24E74(void* arg) {
    MenuData* data = static_cast<MenuData*>(fn_8004E5D8(g_GameGlobal, arg));
    float result;
    if (data->denominator != 0) {
        result = lbl_2_rodata_D9C * (lbl_2_rodata_D9C * ((float)data->numerator / (float)data->denominator));
    } else {
        result = lbl_2_rodata_DA0;
    }
    return (unsigned int)result;
}
