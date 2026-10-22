#pragma force_active on
extern "C" {
extern int *lbl_805A01F8;
extern int lbl_805A01E8;
extern int lbl_805A01F4;
extern char g_thpObject[];
void* memset(void*, int, unsigned long);
int fn_801F6278(int, void*);

int fn_8007BD90(int a, int b) {
    if (*lbl_805A01F8 == 0) return 0;
    if (*(int*)(g_thpObject + 0xA0) != 0) return 0;
    memset(g_thpObject + 0x80, 0, 0xC);
    memset(g_thpObject + 0x8C, 0, 0x10);
    if (fn_801F6278(a, g_thpObject) == 0) return 0;
    lbl_805A01F4 = b;
    lbl_805A01E8 = 0;
    return 1;
}
}
