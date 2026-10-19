#pragma force_active on

extern "C" {
void fn_27_12BAF8(void *, int);
void fn_27_357D00(void *, void *, int);
extern char lbl_27_bss_8094[];
}

struct Wario {
    char padding[0x60];
    void *field;
};

extern "C" void fn_110_8CB4(Wario *wario, int param) {
    fn_27_12BAF8(wario, param);
    fn_27_357D00(lbl_27_bss_8094, wario->field, param);
}
