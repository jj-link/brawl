#pragma force_active on
extern "C" {
extern int fn_8007D5DC(void);
extern char g_thpObject[];

int fn_8007C944(void) {
    if ((*(int*)(g_thpObject + 0xA0) != 0) &&
        ((*(unsigned char*)(g_thpObject + 0xA4) == 1) || (*(unsigned char*)(g_thpObject + 0xA4) == 4))) {
        if ((*(unsigned char*)(g_thpObject + 0xA4) == 4) && (*(unsigned char*)(g_thpObject + 0xA7) != 0)) {
            fn_8007D5DC();
        }
        *(unsigned char*)(g_thpObject + 0xA4) = 2;
        *(int*)(g_thpObject + 0xD0) = 0;
        *(int*)(g_thpObject + 0xD4) = 0;
        *(int*)(g_thpObject + 0xCC) = -1;
        *(int*)(g_thpObject + 0xC8) = -1;
        return 1;
    }
    return 0;
}
}
