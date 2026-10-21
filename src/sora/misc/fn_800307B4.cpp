#pragma force_active on

extern "C" {

struct Lbl804953A0 {
    int unk0;
    int unk4;
    char unk8;
};

struct GfShutdownManager {
    char pad[0xC];
    char unkC;
};

extern int lbl_805A0078;
extern void fn_800306D0(int a, int b);
extern Lbl804953A0 lbl_804953A0;
extern GfShutdownManager g_gfShutdownManager;

void fn_800307B4() {
    int val = lbl_805A0078;
    if (val != 0) {
        fn_800306D0(val, 1);
        lbl_805A0078 = 0;
    }
    lbl_804953A0.unk8 = 1;
    g_gfShutdownManager.unkC = 1;
}

}
