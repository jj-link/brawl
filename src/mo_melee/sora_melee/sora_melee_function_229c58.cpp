#pragma force_active on
typedef unsigned int u32;
typedef int s32;

extern "C" {
extern char* lbl_27_bss_5668;
void fn_27_229C94(void* obj, int flag);
}

extern "C" void fn_27_229C58(void* unused, int flag) {
    if (flag != 0)
        return;
    void* obj = *(void**)(lbl_27_bss_5668 + 0xC4);
    if (obj == 0)
        return;
    u32 w = *(u32*)((char*)obj + 0x40);
    u32 r = ((w >> 8) | (w << 24)) & 0xFF800000;
    if (((s32)r >> 24) != 1)
        return;
    fn_27_229C94(obj, 1);
}
