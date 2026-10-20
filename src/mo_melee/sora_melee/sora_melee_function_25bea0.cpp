#pragma force_active on
struct Application {
    unsigned char pad[0xEC];
    unsigned int flags;
};

struct GameData {
    unsigned char pad[0x4924];
    unsigned char upper : 5;
    unsigned char flags : 1;
    unsigned char lower : 2;
};

struct GameGlobal {
    unsigned char pad[0x30];
    GameData* data;
};

struct Object {
    unsigned char pad[0x48];
    unsigned int state;
};

extern "C" {
extern unsigned char* lbl_27_bss_5668;
extern Application* g_gfApplication;
extern GameGlobal* g_GameGlobal;

void fn_27_25BEA0(Object* self)
{
    if (!lbl_27_bss_5668)
        return;
    if (!lbl_27_bss_5668[0x199])
        return;
    if (g_gfApplication->flags >> 27)
        return;

    g_GameGlobal->data->flags = 1;
    self->state = 1;
}
}
