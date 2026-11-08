#pragma force_active on
#pragma opt_propagation off
typedef signed int s32;
void fn_801EF8CC(s32, void *);
void fn_801EFA80(char *arr) {
    s32 i = 0;
    do {
        *(s32 *)(arr + i * 8) = i;
        fn_801EF8CC(i, arr + i * 8 + 4);
        i++;
    } while (i <= 0x14);
    {
        char *p = arr + i * 8;
        *(s32 *)p = 0x19;
        fn_801EF8CC(0x19, p + 4);
    }
    i++;
    ((s32 *)arr)[i * 2] = 0xFF;
}