#pragma force_active on
typedef unsigned long u32;
typedef unsigned char u8;

struct sndSystem {
    u32 getBGMId();
    void playBGM(int id, u32 param, bool flag);
};

extern "C" int fn_6_308C(u8* self, u8* p);
extern "C" u8* g_GameGlobal;
extern sndSystem* g_sndSystem;

extern "C" {
void fn_5_12E00(u8* self) {
    u8* base = *(u8**)(g_GameGlobal + 0x40);
    int ret = fn_6_308C(self, base + 0x24a0);
    if (ret >= 0) {
        *(u32*)(*(u8**)(self + 0x1ac) + 0x1a0) = *(u32*)(base + 0x24a0);
        u8* ctx = *(u8**)(self + 0x1ac);
        *(int*)(ctx + 0x1b40) = *(u8*)(ctx + 0x1cee) + ret;
    }
    if (g_sndSystem->getBGMId() != 0x270f) {
        g_sndSystem->playBGM(0x270f, 0, true);
    }
}
}
