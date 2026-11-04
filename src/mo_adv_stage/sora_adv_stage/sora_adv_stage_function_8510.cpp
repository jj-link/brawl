#pragma force_active on

extern "C" {
void fn_800E5174(void*, unsigned int);
void setStageOutEffectInit__5StageFv(void*, int);
extern void* g_GameGlobal;
extern void* g_ftManager;
extern void* g_IfAdvMngr;
extern void* g_IfMngr;
}

extern "C" void fn_40_8510(void* arg0, unsigned int arg1) {
    unsigned char* p = (unsigned char*)(*(void**)((char*)g_GameGlobal + 0x30));
    p[0x4924] |= 4;

    if (arg1 == 1) {
        ((unsigned char*)g_ftManager)[0x6e] |= 1;
    }

    ((signed char*)g_ftManager)[0x6c] &= 0xFFFFFF7F;

    if (g_IfAdvMngr != 0) {
        int off;
        int i;
        i = 0;
        off = 0;
        do {
            void* ptr = *(void**)((char*)g_IfAdvMngr + off + 0xe8);
            if (ptr != 0) {
                fn_800E5174(ptr, 0);
            }
            i++;
            off += 4;
        } while (i < 4);
    }

    if (g_IfMngr != 0) {
        int i = 0;
        int off = 0;
        do {
            void* ptr = *(void**)((char*)g_IfMngr + off + 0x4c);
            if (ptr != 0) {
                unsigned char playerNo = ((unsigned char*)g_IfMngr)[0x68 + i];
                void* target = *(void**)((char*)g_IfMngr + (int)playerNo * 4 + 0x4c);
                fn_800E5174(target, 0);
            }
            i++;
            off += 4;
        } while (i < 4);
    }

    setStageOutEffectInit__5StageFv(arg0, 1);
}
