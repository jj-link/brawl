#pragma force_active on
extern "C" {
    extern void* g_gfFileIOManager;
    void fn_800237A0(void*, int);

    int fn_8004B738(int* arg0) {
        if (*arg0 != 1) {
            return 0;
        }
        *arg0 = 0;
        fn_800237A0(g_gfFileIOManager, 0);
        return 1;
    }
}
