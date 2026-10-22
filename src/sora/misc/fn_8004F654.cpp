#pragma force_active on
extern "C" {
extern void* g_GameGlobal;
unsigned int* fn_8004E580(void*);
int fn_8004F654(void) {
    unsigned int* bits = fn_8004E580(g_GameGlobal);
    for (int i = 0; i < 14; ++i) {
        int bit = i * 3 + 1;
        if (!(bits[bit / 32] & (1 << (bit % 32)))) return 0;
    }
    return 1;
}
}
