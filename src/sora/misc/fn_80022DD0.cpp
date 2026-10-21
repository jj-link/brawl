#pragma force_active on
extern int g_gfFileIOManager;

extern "C" {
void fn_80022E10(int mgr, int a, int b);

void fn_80022DD0(int a, int b)
{
    fn_80022E10(g_gfFileIOManager, a, b);
}
}
