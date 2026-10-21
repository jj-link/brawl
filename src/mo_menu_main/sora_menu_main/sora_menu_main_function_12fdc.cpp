#pragma force_active on

extern "C" {
extern void* g_sndSystem;
extern char* g_gfApplication;
extern unsigned char lbl_2_rodata_4F0[];

void fn_80073F84(void*, int);
unsigned char* fn_80023AC8();
char* getInstance__14gfSceneManagerFv();
void startKeepScreen__17gfKeepFrameBufferFv(void*);
}

extern "C" void fn_2_12FDC(char* self, int idx) {
    switch (lbl_2_rodata_4F0[idx]) {
    case 0:
        break;
    case 1:
        fn_80073F84(g_sndSystem, 0);
        break;
    case 2:
        fn_80073F84(g_sndSystem, 0x1E);
        break;
    }

    unsigned char b28 = self[0xABF];
    unsigned char b29 = self[0xABE];
    unsigned char b30 = self[0xABD];
    unsigned char b31 = self[0xABC];

    unsigned char* mgr = fn_80023AC8();
    mgr[0x2C] = b31;
    mgr[0x2D] = b30;
    mgr[0x2E] = b29;
    mgr[0x2F] = b28;

    char* inst = getInstance__14gfSceneManagerFv();
    *(int*)(inst + 0x284) = idx;
    *(int*)(inst + 0x288) = 2;

    startKeepScreen__17gfKeepFrameBufferFv(g_gfApplication + 0xD0);
}
