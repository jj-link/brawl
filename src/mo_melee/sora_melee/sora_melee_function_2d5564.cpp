#pragma force_active on
extern "C" void fn_27_2D7B58(void* state, void* update);
extern const float lbl_27_rodata_61E8;

extern "C" void fn_27_2D5564(void* arg0) {
    unsigned char* base = (unsigned char*)arg0;
    unsigned char* p = (unsigned char*)arg0;
    for (int i = 0; i < 2; i++) {
        *(float*)(p + 0x304) = lbl_27_rodata_61E8;
        *(float*)(p + 0x308) = lbl_27_rodata_61E8;
        *(float*)(p + 0x30C) = lbl_27_rodata_61E8;
        *(float*)(p + 0x310) = lbl_27_rodata_61E8;
        *(float*)(p + 0x314) = lbl_27_rodata_61E8;
        *(float*)(p + 0x318) = lbl_27_rodata_61E8;
        *(float*)(p + 0x31C) = lbl_27_rodata_61E8;
        *(float*)(p + 0x320) = lbl_27_rodata_61E8;
        *(float*)(p + 0x324) = lbl_27_rodata_61E8;
        *(float*)(p + 0x328) = lbl_27_rodata_61E8;
        *(float*)(p + 0x32C) = lbl_27_rodata_61E8;
        *(float*)(p + 0x330) = lbl_27_rodata_61E8;
        *(float*)(p + 0x334) = lbl_27_rodata_61E8;
        *(float*)(p + 0x338) = lbl_27_rodata_61E8;
        *(float*)(p + 0x33C) = lbl_27_rodata_61E8;
        *(float*)(p + 0x340) = lbl_27_rodata_61E8;
        *(float*)(p + 0x344) = lbl_27_rodata_61E8;
        *(float*)(p + 0x348) = lbl_27_rodata_61E8;
        *(float*)(p + 0x34C) = lbl_27_rodata_61E8;
        *(float*)(p + 0x350) = lbl_27_rodata_61E8;
        *(float*)(p + 0x354) = lbl_27_rodata_61E8;
        *(float*)(p + 0x358) = lbl_27_rodata_61E8;
        *(float*)(p + 0x35C) = lbl_27_rodata_61E8;
        *(float*)(p + 0x360) = lbl_27_rodata_61E8;
        *(float*)(p + 0x364) = lbl_27_rodata_61E8;
        *(float*)(p + 0x368) = lbl_27_rodata_61E8;
        *(float*)(p + 0x36C) = lbl_27_rodata_61E8;
        *(float*)(p + 0x370) = lbl_27_rodata_61E8;
        *(float*)(p + 0x374) = lbl_27_rodata_61E8;
        *(float*)(p + 0x378) = lbl_27_rodata_61E8;
        *(float*)(p + 0x37C) = lbl_27_rodata_61E8;
        *(float*)(p + 0x380) = lbl_27_rodata_61E8;
        *(float*)(p + 0x384) = lbl_27_rodata_61E8;
        *(float*)(p + 0x388) = lbl_27_rodata_61E8;
        *(float*)(p + 0x38C) = lbl_27_rodata_61E8;
        *(float*)(p + 0x390) = lbl_27_rodata_61E8;
        *(float*)(p + 0x394) = lbl_27_rodata_61E8;
        *(float*)(p + 0x398) = lbl_27_rodata_61E8;
        *(float*)(p + 0x39C) = lbl_27_rodata_61E8;
        *(float*)(p + 0x3A0) = lbl_27_rodata_61E8;
        *(float*)(p + 0x3A4) = lbl_27_rodata_61E8;
        *(float*)(p + 0x3A8) = lbl_27_rodata_61E8;
        *(float*)(p + 0x3AC) = lbl_27_rodata_61E8;
        *(float*)(p + 0x3B0) = lbl_27_rodata_61E8;
        *(float*)(p + 0x3B4) = lbl_27_rodata_61E8;
        *(float*)(p + 0x3B8) = lbl_27_rodata_61E8;
        *(float*)(p + 0x3BC) = lbl_27_rodata_61E8;
        *(float*)(p + 0x3C0) = lbl_27_rodata_61E8;
        p += 0xC0;
    }

    unsigned char* r31 = base + 4;
    int idx = 0;
    do {
        if (!(*(unsigned char*)(base + idx + 0x488) & 0x80)) {
            void* v = *(void**)(r31 + 8);
            if (v != 0) {
                fn_27_2D7B58(arg0, v);
            }
        }
        idx += 1;
        r31 += 0xC;
    } while (idx < 0x40);
}
