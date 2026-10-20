#pragma force_active on
struct Data {
    unsigned int words[7];
};

extern "C" Data lbl_27_bss_6A38;

extern "C" void fn_27_2A2294(const Data* source) {
    lbl_27_bss_6A38 = *source;
}
