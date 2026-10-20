#pragma force_active on
struct FnWork {
    void* a;
    void* b;
    unsigned int c;
};

extern "C" {
    extern char lbl_27_data_3A068[];

    void fn_27_1992F4(FnWork* w) {
        unsigned int v = w->c;
        w->a = lbl_27_data_3A068;
        w->b = lbl_27_data_3A068 + 0x48;
        w->c = v & 0x7FFFF;
    }
}
