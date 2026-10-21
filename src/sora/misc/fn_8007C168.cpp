#pragma force_active on
extern "C" {
extern int fn_801F6524(void);
extern char g_thpObject[];

int fn_8007C168(void) {
    if ((*(int*)(g_thpObject + 0xA0) != 0) && (*(unsigned char*)(g_thpObject + 0xA4) == 0)) {
        *(int*)(g_thpObject + 0xA0) = 0;
        fn_801F6524();
        return 1;
    }
    return 0;
}
}
