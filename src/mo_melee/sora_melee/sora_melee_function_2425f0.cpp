#pragma force_active on
extern void* g_sndSystem;
extern "C" int fn_80074184(void* snd, void* arg);

extern "C" {
void fn_27_2425F0(char* self) {
    if (fn_80074184(g_sndSystem, *(void**)(self + 0x64))) {
        *(unsigned char*)(self + 0x40) = 3;
    }
}
}
