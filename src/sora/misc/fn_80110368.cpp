#pragma force_active on
extern void* g_GameGlobal;
extern "C" int fn_8004D9A8(void* p, int i);
extern "C" void* getGlobalRecordMenuDatap__10GameGlobalFv(void* global);

struct Flags1B {
    unsigned char f7 : 1;
    unsigned char f6 : 1;
    unsigned char rest : 6;
};

extern "C" void fn_80110368(unsigned char* p) {
    if (p != 0) {
        if (p[1] != 0 || !((p[0x3E] >> 7) & 1) || p[0x3D] == 0) {
            p[0x1B] = (unsigned char)(p[0x1B] & ~0x40);
            return;
        }
        if (p[0x18] != 0x78) {
            int v = fn_8004D9A8(g_GameGlobal, p[0x18]);
            ((Flags1B*)(p + 0x1B))->f6 = (unsigned char)v;
            return;
        }
        {
            unsigned char* base =
                (unsigned char*)getGlobalRecordMenuDatap__10GameGlobalFv(g_GameGlobal);
            unsigned char idx = p[0x3D];
            int v = base[idx + 0xF];
            ((Flags1B*)(p + 0x1B))->f6 = (unsigned char)v;
        }
    }
}
