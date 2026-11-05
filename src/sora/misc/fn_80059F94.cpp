#pragma force_active on
typedef unsigned int u32;

extern "C" void* fn_8004E5B8(char*);
extern "C" char* g_GameGlobal;

extern "C" int fn_80059F94(int arg0) {
    int ret = 0;
    switch (arg0) {
    case 0x7C:
        if (*(u32*)fn_8004E5B8(g_GameGlobal) & 0x10000) {
            ret = 1;
        }
        if (*(u32*)fn_8004E5B8(g_GameGlobal) & 0x40000) {
            ret = 1;
        }
        if (*(u32*)fn_8004E5B8(g_GameGlobal) & 0x100000) {
            ret = 1;
        }
        if (*(u32*)fn_8004E5B8(g_GameGlobal) & 0x400000) {
            ret = 1;
        }
        break;
    case 0x7D:
        if (*(u32*)fn_8004E5B8(g_GameGlobal) & 0x40000) {
            ret = 1;
        }
        if (*(u32*)fn_8004E5B8(g_GameGlobal) & 0x100000) {
            ret = 1;
        }
        if (*(u32*)fn_8004E5B8(g_GameGlobal) & 0x400000) {
            ret = 1;
        }
        break;
    case 0x7E:
        if (*(u32*)fn_8004E5B8(g_GameGlobal) & 0x100000) {
            ret = 1;
        }
        if (*(u32*)fn_8004E5B8(g_GameGlobal) & 0x400000) {
            ret = 1;
        }
        break;
    case 0x7F:
        if (*(u32*)fn_8004E5B8(g_GameGlobal) & 0x400000) {
            ret = 1;
        }
        break;
    }
    return ret;
}
