#pragma force_active on
extern "C" {

typedef unsigned char u8;

struct gmGlobalModeMelee {
    char _0[0x60];
    u8 m_0x60;
};

struct GameGlobal {
    void* m_appData;
    char _0[0x4];
    gmGlobalModeMelee* m_modeMelee;
    char _1[0x4];
};

extern GameGlobal* g_GameGlobal;
void fn_8005630C(u8);

void fn_800516F0(void) {
    fn_8005630C(g_GameGlobal->m_modeMelee->m_0x60);
}

}
