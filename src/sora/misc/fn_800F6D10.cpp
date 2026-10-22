#pragma force_active on
struct sndSystem;
typedef unsigned long SndID;

extern "C" void fn_800F6DF4(void* self, int a, int b, int c, int d);
extern "C" int fn_800B61C0(void*);
extern "C" void playSE__9sndSystemF5SndIDiiii(sndSystem* self, SndID id, int a, int b, int c, int d);
extern sndSystem* g_sndSystem;

struct FtObj {
    char pad0[0x8C];
    int unk8C;
    char pad1[0x9C - 0x90];
    void* unk9C;
    char pad2[0x42C - 0xA0];
    int unk42C;
};

extern "C" void fn_800F6D10(FtObj* self) {
    if (self->unk8C == 0) {
        fn_800F6DF4(self, 0, 0, self->unk42C, 0);
    } else if (self->unk8C == 7) {
        playSE__9sndSystemF5SndIDiiii(g_sndSystem, 0xE9, -1, 0, 0, -1);
    }
    fn_800B61C0(self->unk9C);
}
