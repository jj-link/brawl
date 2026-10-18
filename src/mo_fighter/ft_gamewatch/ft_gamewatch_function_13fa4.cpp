#pragma force_active on
struct VFT2 {
    unsigned long _[16];
};

extern "C" extern VFT2 lbl_107_data_95D0;

extern "C" void fn_107_13FA4(VFT2 **object) {
    *object = &lbl_107_data_95D0;
}