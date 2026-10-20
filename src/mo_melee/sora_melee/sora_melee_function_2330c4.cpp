#pragma force_active on
extern "C" void fn_40_13340(void* r, void* a, void* b);

extern "C" {
extern void* g_stTriggerMng;
}

extern "C" void fn_27_2330C4(void* a, void* b) {
    char* s = (char*)g_stTriggerMng;
    if (s) {
        for (unsigned int i = 0; i < *(unsigned int*)(s + 0x50); i++) {
            char* base = (char*)*(int*)(s + 0x4c);
            fn_40_13340(*(void**)(base + i * 4), a, b);
        }
    }
}