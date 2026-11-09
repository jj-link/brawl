#pragma force_active on
extern void fn_803D634C(void *p, int a, unsigned int b);
extern void *fn_803E2414(void *a, void *b, unsigned int c, void *d);
typedef struct { unsigned int w[0x90]; } Blob240;
void *fn_803E47A4(void *arg0, void *arg1, int arg2)
{
    char *var_r6 = (char *)arg0;
    char *var_r7 = (char *)arg0 + 0x40;
    unsigned int var_r31 = 0;
    char *var_r30 = 0;
    unsigned int var_r8 = 0;
    int i;
    for (i = 0; i < 5; i++) {
        if (!(*(unsigned int *)(var_r6 + 0x40) & 1) || ((*(unsigned int *)(var_r6 + 0x40) & 1) && ((*(unsigned int *)(var_r6 + 0x40) == 0) & 2))) {
            if (var_r30 == 0) {
                var_r30 = var_r7;
                var_r31 = var_r8;
            }
        } else if (*(unsigned int *)((char *)arg1 + 0x22C) == *(unsigned int *)(var_r6 + 0x2A8) &&
                   *(unsigned int *)((char *)arg1 + 0x238) == *(unsigned int *)(var_r6 + 0x2B4) &&
                   *(unsigned short *)((char *)arg1 + 0x23C) == *(unsigned short *)(var_r6 + 0x2B8)) {
            return (char *)arg0 + var_r8 * 0x29C + 0x40;
        }
        var_r6 += 0x29C;
        var_r7 += 0x29C;
        var_r8++;
    }
    if (var_r30 == 0) return 0;
    *(int *)var_r30 = 3;
    *(short *)(var_r30 + 0x298) = 0;
    *(Blob240 *)(var_r30 + 0x3C) = *(Blob240 *)arg1;
    *(short *)(var_r30 + 0x27C) = 0;
    *(short *)(var_r30 + 0x27E) = 0;
    *(int *)(var_r30 + 0x280) = 0;
    *(int *)(var_r30 + 0x284) = 0;
    *(int *)(var_r30 + 0x288) = 0;
    fn_803E2414(var_r30 + 4, 0, *(unsigned int *)((char *)arg1 + 0x22C), var_r30 + 0x270);
    if (*(unsigned short *)((char *)arg0 + 0x1FB0) & 1) {
        unsigned int n = *(unsigned int *)((char *)arg0 + 0x1FB8);
        char *p = *(char **)((char *)arg0 + 0x1FB4) + ((var_r31 * n) << 2);
        *(char **)(var_r30 + 0x20) = p;
        fn_803D634C(p, 0, *(unsigned int *)((char *)arg0 + 0x1FB8) << 2);
        *(unsigned int *)(var_r30 + 0x2C) = *(unsigned int *)((char *)arg0 + 0x1FB8);
        *(unsigned short *)(var_r30 + 0x24) = *(unsigned short *)((char *)arg0 + 0x1FB2);
        *(short *)(var_r30 + 0x26) = 0;
        *(int *)(var_r30 + 0x28) = 0;
        *(int *)(var_r30 + 0x30) = 0;
        if (*(int *)((char *)arg1 + 0x228) != 0 && *(int *)(var_r30 + 0x2C) != 0) {
            **(int **)(var_r30 + 0x20) = *(int *)((char *)arg1 + 0x234);
            *(int *)(var_r30 + 0x28) = *(int *)(var_r30 + 0x28) + 1;
        }
    }
    return var_r30;
}