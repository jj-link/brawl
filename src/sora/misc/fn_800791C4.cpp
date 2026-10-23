#pragma force_active on
extern "C" int fn_80074184(int, int);
extern int g_sndSystem;

extern "C" void fn_800791C4(int arg0) {
    fn_80074184(g_sndSystem, *(int*)(arg0 + 0x178));
}
