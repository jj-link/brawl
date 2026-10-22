#pragma force_active on

extern "C" {

extern unsigned int* fn_8004E580(int);
extern int g_GameGlobal;
extern const unsigned char lbl_80407A40[];

int isCharUsable__6muMenuFiii(int a, int b, int c) {
    unsigned int* bits = fn_8004E580(g_GameGlobal);
    int n = (lbl_80407A40 + ((a << 2) - a))[1];
    if (n != 0xE) {
        int val = (n << 2) - n + 1;
        if (!(bits[val / 32] & (1 << (val % 32)))) {
            return 0;
        }
    }
    return 1;
}

}
