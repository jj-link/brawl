#pragma force_active on

typedef int s32;
typedef unsigned int u32;

extern "C" {
    void* getInstance__14gfSceneManagerFv();
    void fn_800568C8(void);
    void fn_800569CC(void);
    extern void* lbl_1_bss_1B74;
    extern unsigned char lbl_1_bss_1B84;
}

extern "C" void fn_1_3A52C(s32* self) {
    s32 temp_r4;

    self[6] = *(s32*)((char*)getInstance__14gfSceneManagerFv() + 0x31C);
    lbl_1_bss_1B84 = 0;
    if (lbl_1_bss_1B74 == 0) {
        lbl_1_bss_1B74 = getInstance__14gfSceneManagerFv();
    }
    temp_r4 = self[6];
    switch (temp_r4) {
    case 23:
        self[2] = 6;
        fn_800569CC();
        return;
    case 1:
    case 3:
    case 4:
    case 5:
    case 7:
    case 9:
    case 12:
    case 15:
    case 17:
    case 19:
    case 21:
    case 22:
        self[5] = temp_r4;
        fn_800569CC();
        self[2] = 6;
        return;
    case 18:
    case 20:
        self[5] = temp_r4;
        fn_800569CC();
        self[2] = 0xA;
        return;
    case 0:
    case 2:
        self[5] = temp_r4;
        fn_800569CC();
        fn_800568C8();
        self[2] = 0;
        return;
    default:
        self[5] = temp_r4;
        fn_800569CC();
        self[2] = 0;
        return;
    }
}
