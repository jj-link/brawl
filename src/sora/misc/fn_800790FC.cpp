#pragma force_active on
extern "C" void fn_80073F84(void*);
extern void* g_sndSystem;

extern "C" void fn_800790FC(void) {
    fn_80073F84(g_sndSystem);
}
