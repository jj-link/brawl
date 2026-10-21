#pragma force_active on
struct GameGlobalStub {
    char pad[0x24];
    char *sub;
};

extern struct GameGlobalStub *g_GameGlobal;

extern "C" {
void fn_800531E0(int value)
{
    if (value < 0) {
        value = 0;
    }
    if (value > 0x40) {
        value = 0x40;
    }
    g_GameGlobal->sub[0x32b] = value;
}
}
