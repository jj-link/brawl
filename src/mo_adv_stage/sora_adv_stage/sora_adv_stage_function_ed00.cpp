#pragma force_active on
extern "C" {
extern void* g_sndSystem;
extern void* lbl_40_bss_15C;
extern const float lbl_40_rodata_14C;
void playSE__9sndSystemF5SndIDiiii(void*, int, int, int, int, int);
void fn_40_6FEC(void* self);

void fn_40_ED00(void* self) {
    char* s = (char*)self;
    char* p = *(char**)(s + 0x10);
    if ((unsigned char)p[5] != 0) {
        playSE__9sndSystemF5SndIDiiii(g_sndSystem, 0x227c, -1, 0, 0, -1);
        *(unsigned char*)(s + 0x18) = 3;
        *(unsigned char*)(s + 0x19) = 3;
        *(float*)(s + 0x14) = lbl_40_rodata_14C;
        *(unsigned char*)(s + 0x1a) = 0;
    } else {
        *(unsigned char*)(s + 0x18) = 9;
    }
    *(unsigned char*)(s + 0x1b) = 1;
    fn_40_6FEC(lbl_40_bss_15C);
}
}
