#pragma force_active on

struct NTE {
    unsigned char pad[0x83];
    unsigned char flag;
};

struct GG {
    int pad[0x34 / 4];
    NTE* nte;
};

extern "C" {
extern GG* g_GameGlobal;

int fn_8014FD6C()
{
    return g_GameGlobal->nte->flag & 1;
}
}
