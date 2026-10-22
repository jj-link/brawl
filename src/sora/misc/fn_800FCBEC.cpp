#pragma force_active on

typedef unsigned char u8;
typedef signed char s8;
typedef int s32;

struct IfWifiprMngr {
    char pad0[0x18];
    s32 unk18;
    s32 unk1C[7];
    void* unk38;
    char pad3C[0x14];
    s8 unk50;

    void main();
};

struct Inner {
    char pad[0x1C];
    u8 unk1C;
};

extern "C" {
void fn_800FD448(s32);
void fn_800FD8E0(s32);
s32 fn_800FBFDC();
void fn_8000DB40(void*, int);
}
extern s32 g_gfSceneRoot;

void IfWifiprMngr::main() {
    fn_800FD448(unk18);
    for (int i = 0; i < 7; i++) {
        fn_800FD8E0(unk1C[i]);
    }
    if (((Inner*)unk38)->unk1C != 0) {
        if (fn_800FBFDC() == 4) {
            unk50 = 1;
        }
    }
    fn_8000DB40((void*)g_gfSceneRoot, 8);
}
