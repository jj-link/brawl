#pragma force_active on
struct soController {
    enum PadButton { Dummy };
    static unsigned int getButtonMask(PadButton b);
};

extern const unsigned int lbl_27_rodata_75C[17];

unsigned int soController::getButtonMask(PadButton b) {
    if ((int)b <= -1 || (int)b >= 17) return 0;
    return lbl_27_rodata_75C[b];
}
