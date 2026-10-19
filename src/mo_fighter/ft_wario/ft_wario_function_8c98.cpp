#pragma force_active on
extern "C" char lbl_27_bss_8094[];
extern "C" void fn_27_357CAC(void *, void *, void *);

struct Wario
{
    char padding[0x60];
    void *field;
};

extern "C" void fn_110_8C98(Wario *wario)
{
    fn_27_357CAC(lbl_27_bss_8094, wario->field, reinterpret_cast<char *>(wario) + 0xD2FC);
}
