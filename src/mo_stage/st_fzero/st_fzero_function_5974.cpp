#pragma force_active on
extern "C" float randf__Fv();
extern "C" void playSE__9sndSystemF5SndIDiiii(void*, int, int, int, int, int);
extern "C" void* g_sndSystem;
extern "C" const float lbl_61_rodata_50[40];

extern "C" void fn_61_5974()
{
    const float* tbl = lbl_61_rodata_50;
    float r = randf__Fv();
    int id;
    if (r < tbl[37]) {
        id = 0x1c78;
    } else if (r < tbl[38]) {
        id = 0x1c79;
    } else if (r < tbl[39]) {
        id = 0x1c7a;
    } else {
        id = 0x1c7b;
    }
    playSE__9sndSystemF5SndIDiiii(g_sndSystem, id, 0, 0, 0, -1);
}
