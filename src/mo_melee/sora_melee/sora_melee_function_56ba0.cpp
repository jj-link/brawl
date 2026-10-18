#pragma force_active on
struct SoundSystem;

extern "C" SoundSystem *g_sndSystem;
extern "C" void fn_800778CC(SoundSystem *);

extern "C" void fn_27_56BA0()
{
    fn_800778CC(g_sndSystem);
}
