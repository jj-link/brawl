#pragma force_active on
struct Entry {
    unsigned char data[0x214];
};

extern Entry lbl_27_bss_3210[];

extern "C" void *fn_27_1487F0() {
    void *base = lbl_27_bss_3210;
    void *p = *reinterpret_cast<void **>(
        reinterpret_cast<unsigned char *>(base) + 0x210
    );
    return *reinterpret_cast<void **>(
        reinterpret_cast<unsigned char *>(p) + 0xA4
    );
}
