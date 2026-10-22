#pragma force_active on

extern "C" char g_thpObject[];
extern "C" void* lbl_805A01F8;

extern "C" void fn_802022DC(int, int);

extern "C" int fn_8007CB08(void) {
    if ((*(int*)(g_thpObject + 0xA0) != 0) && (*(unsigned char*)(g_thpObject + 0xA4) == 2)) {
        g_thpObject[0xA5] = 4;
        g_thpObject[0xA4] = 4;
        if (*(unsigned char*)(g_thpObject + 0xA7) != 0) {
            if (*(int*)((char*)lbl_805A01F8 + 0x7F8) != 0) {
                fn_802022DC(*(int*)((char*)lbl_805A01F8 + 0x7F8), 0);
            }
            if (*(int*)((char*)lbl_805A01F8 + 0x7FC) != 0) {
                fn_802022DC(*(int*)((char*)lbl_805A01F8 + 0x7FC), 0);
            }
        }
        return 1;
    }
    return 0;
}
