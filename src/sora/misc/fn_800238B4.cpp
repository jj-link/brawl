#pragma force_active on
extern "C" void fn_80022E10(int mgr);
extern "C" int g_gfFileIOManager;

extern "C" int fn_800238B4(int unused, int arg2) {
    if (arg2 != 0) {
        return 0;
    }
    fn_80022E10(g_gfFileIOManager);
    return 1;
}
