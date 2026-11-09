#pragma force_active on
typedef unsigned char u8;

extern "C" void* fn_8004E5C4(void*);
extern "C" void* g_GameGlobal;

struct Obj {
    u8 _pad[0x808];
    u8 m_flag : 1;
    u8 m_rest : 7;
};

static void setFlag(bool b) {
    ((Obj*)fn_8004E5C4(g_GameGlobal))->m_flag = b;
}

extern "C" void fn_80052644(void) {
    setFlag(true);
    u8* m = *(u8**)((u8*)g_GameGlobal + 8);
    m[0x62] |= 0x80;
}
