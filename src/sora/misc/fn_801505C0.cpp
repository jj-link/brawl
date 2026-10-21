#pragma force_active on
struct Sub { unsigned char pad[0x19]; unsigned char flag; };
struct GameGlobal { unsigned char pad[0x38]; Sub* sub; };

extern GameGlobal* g_GameGlobal;

extern "C" {
unsigned int fn_801505C0(void) {
    unsigned int v = g_GameGlobal->sub->flag;
    return (unsigned int)(-v | v) >> 31;
}
}
