#pragma force_active on
struct GameGlobal;
struct MenuValue {
    unsigned int unused[2];
    unsigned int numerator;
    unsigned int denominator;
};
extern "C" {
extern GameGlobal* g_GameGlobal;
MenuValue* fn_8004D138(GameGlobal*, void*);
extern const float lbl_2_rodata_D9C;
extern const float lbl_2_rodata_DA0;
unsigned int fn_2_24F00(void* arg) {
    MenuValue* value = fn_8004D138(g_GameGlobal, arg);
    float result;
    if (value->denominator != 0) {
        result = lbl_2_rodata_D9C * (lbl_2_rodata_D9C *
            ((float)value->numerator / (float)value->denominator));
    } else {
        result = lbl_2_rodata_DA0;
    }
    return (unsigned int)result;
}
}