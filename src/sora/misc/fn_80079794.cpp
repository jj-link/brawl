#pragma force_active on
extern "C" void stopSE__14snd3DGeneratorFll(void*, int, int);
extern "C" void fn_80075F1C(void*, int, int);
extern void* g_sndSystem;

extern "C" void stopSE__14snd3DGeneratorFll(void* self, int arg0, int arg1) {
    fn_80075F1C(g_sndSystem, arg0, arg1);
}
