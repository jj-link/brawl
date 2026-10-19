#pragma force_active on

extern "C" char lbl_27_bss_8094[];
extern "C" void fn_27_12DCA8();
extern "C" void fn_27_357E18(void *, void *, void *, void *);

struct Wario {
    char padding[0x60];
    void *field;
};

struct Nested {
    char padding[0x88];
    void *field;
};

extern "C" void fn_110_90B4(Wario *wario) {
    fn_27_12DCA8();
    Nested *nested = *reinterpret_cast<Nested **>(
        reinterpret_cast<char *>(wario) + 0xD2F8);
    fn_27_357E18(lbl_27_bss_8094, nested->field, wario->field,
                 reinterpret_cast<char *>(wario) + 0xD2FC);
}
