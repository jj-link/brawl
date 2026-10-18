#pragma force_active on
class sndSystem;

extern sndSystem* g_sndSystem;

extern "C" void fn_80076E30(sndSystem*);

extern "C" void fn_27_56C30() {
    fn_80076E30(g_sndSystem);
}
