#pragma force_active on
extern "C" float randf__Fv();
extern "C" void playSE__9sndSystemF5SndIDiiii(void*, int, int, int, int, int);
extern void* g_sndSystem;
extern const float lbl_61_rodata_50[];

extern "C" void fn_61_58E8()
{
    const float* tbl = lbl_61_rodata_50;
    float r = randf__Fv();
    int id;
    if (r < tbl[37]) {
        id = 0x1c74;
    } else if (r < tbl[38]) {
        id = 0x1c75;
    } else if (r < tbl[39]) {
        id = 0x1c76;
    } else {
        id = 0x1c77;
    }
    playSE__9sndSystemF5SndIDiiii(g_sndSystem, id, 0, 0, 0, -1);
}
