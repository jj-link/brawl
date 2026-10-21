#pragma force_active on

extern "C" {
extern unsigned char lbl_1_rodata_86C[];
extern void* g_sndSystem;
extern char* g_gfApplication;

void fn_80073F84(void*, int);
void* fn_80023AC8(void);
void* getInstance__14gfSceneManagerFv(void);
void startKeepScreen__17gfKeepFrameBufferFv(void*);
}

extern "C" void fn_1_135E0(char* self, int arg1) {
    unsigned char kind = lbl_1_rodata_86C[arg1];
    switch (kind) {
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

    char* sm = (char*)fn_80023AC8();
    sm[0x2C] = b31;
    sm[0x2D] = b30;
    sm[0x2E] = b29;
    sm[0x2F] = b28;

    char* mgr = (char*)getInstance__14gfSceneManagerFv();
    *(int*)(mgr + 0x284) = arg1;
    *(int*)(mgr + 0x288) = 2;

    startKeepScreen__17gfKeepFrameBufferFv(g_gfApplication + 0xD0);
}
