#pragma force_active on
void fn_80232034(unsigned char *dst, const unsigned char *src);
void *memcpy(void *dest, const void *src, unsigned int n);
extern char lbl_80529994[];

int fn_80234028(const unsigned char *arg0, void *arg1, const unsigned char *arg2, int arg3) {
    struct {
        unsigned char buf[0x25];
        char sp2D;
        char pad[0xD8];
        char sp106;
        char pad2[0x10];
        char sp117;
    } local;

    if (arg3 != 0) {
        fn_80232034(local.buf, arg0);
        memcpy(&local.buf[6], arg2, 0x1F);
        local.sp2D = 0;
        local.sp117 = 0;
        local.sp106 = 0;
        if (*(int *)(lbl_80529994 + 0x50) != 0) {
            ((void (*)(int, int))(*(void **)(lbl_80529994 + 0x50)))(3, (int)local.buf);
        }
    }
    return 0;
}
