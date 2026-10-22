#pragma force_active on

extern "C" {
extern int lbl_805A0214;
extern void* lbl_805A022C;
extern unsigned char lbl_805A024C;
extern unsigned char lbl_8049DDD0[];
extern unsigned char lbl_8049DDF0[];
extern unsigned char g_thpObject[];

int fn_801F6278(void* a, void* b);
int fn_801F6708(void* a, void* b, int c, int d, int e, int f);
}

extern "C" void fn_8007EE24(void) {
    if (lbl_805A0214 != 0) {
        unsigned char* base = lbl_8049DDF0;
        int temp_r30 = ((int*)lbl_805A022C)[1];
        fn_801F6278(lbl_8049DDD0, base + 0x3C);
        fn_801F6708(base + 0x3C, lbl_805A022C, temp_r30, *(int*)(g_thpObject + 0x68), 0, 2);
        *((unsigned char*)&lbl_805A024C + 1) = 1;
    }
}
