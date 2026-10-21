#pragma force_active on
// main/sora_minigame - fn_802DA2B4

struct S0 {
    unsigned short pad0;
    unsigned short unk2;
};

extern "C" {
extern void* lbl_805A0EC8;
void fn_8027EABC(void*, void*, unsigned int, int);

void fn_802DA2B4(S0* arg0) {
    fn_8027EABC(lbl_805A0EC8, arg0, arg0->unk2, 4);
}
}
