#pragma force_active on
extern "C" {
int fn_80056780(void);
extern void *g_GameGlobal;

int fn_80052848(void) {
    int idx = fn_80056780();
    char *base = (char *)((int *)g_GameGlobal)[9];
    return (*(unsigned short *)(base + (idx * 2) + 0x842) >> 12) & 1;
}
}
