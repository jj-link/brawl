#pragma force_active on
extern "C" {
struct StageView {
    int unk[17];
};

extern StageView* lbl_27_bss_5668;
void fn_40_652C();

void fn_27_2331A0() {
    StageView* stage = lbl_27_bss_5668;
    if (stage != 0 && stage->unk[17] == 0x3D)
        fn_40_652C();
}
}