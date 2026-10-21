#pragma force_active on
extern "C" {
extern void fn_800237A0(void* p, int flag);
extern void* g_gfFileIOManager;

void fn_8004B31C(void) {
    fn_800237A0(g_gfFileIOManager, 1);
}
}
