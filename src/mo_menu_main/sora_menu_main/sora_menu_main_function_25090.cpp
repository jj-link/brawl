#pragma force_active on
struct GameGlobal;
struct MenuRecord { char pad[0x24]; unsigned int value; };
extern "C" {
extern GameGlobal* g_GameGlobal;
MenuRecord* fn_8004D138(GameGlobal*, int);
extern const float lbl_2_rodata_DA0;
extern const float lbl_2_rodata_D9C;
}
extern "C" unsigned int fn_2_25090(int arg) {
    float total = lbl_2_rodata_DA0;
    for (int i = 0; i < 120; ++i) {
        total += (float)fn_8004D138(g_GameGlobal, i)->value;
    }
    float result = lbl_2_rodata_DA0;
    if (total > result) {
        result = lbl_2_rodata_D9C * (lbl_2_rodata_D9C * ((float)fn_8004D138(g_GameGlobal, arg)->value / total));
    }
    return (unsigned int)result;
}
