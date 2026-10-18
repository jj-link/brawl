#pragma force_active on
extern "C" void* g_sndSystem;
extern "C" void fn_80075F1C(void*, unsigned int, int);

extern "C" void fn_27_56BE0() {
    ((void (*)(void*))fn_80075F1C)(g_sndSystem);
}
