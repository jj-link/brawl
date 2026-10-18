#pragma force_active on
struct SndObj {
    char pad[0x38];
    void* field38;
};

extern "C" {
    extern void* g_sndSystem;
    void fn_800765B0(void* sys, void* arg, int flag);

    void fn_27_56BAC(SndObj* obj)
    {
        fn_800765B0(g_sndSystem, obj->field38, 0);
    }
}
