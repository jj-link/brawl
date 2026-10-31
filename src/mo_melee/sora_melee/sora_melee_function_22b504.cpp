#pragma force_active on
extern "C" {
extern void* g_stTriggerMng;
void fn_27_2325B0(void* a, void* b);

void fn_27_22B504(void* a, void* b, void* c) {
    if (g_stTriggerMng != 0) {
        fn_27_2325B0(g_stTriggerMng, c);
    }
}
}
