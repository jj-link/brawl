#pragma force_active on
typedef struct {
    unsigned int unk0;
    int unk4;
} BssObj;

extern BssObj lbl_27_bss_1B20;
extern BssObj lbl_27_bss_1B28;

extern "C" {
void fn_27_8D794(void)
{
    lbl_27_bss_1B20.unk0 = 0xff;
    lbl_27_bss_1B20.unk4 = 0;
    lbl_27_bss_1B28.unk0 = 0xff;
    lbl_27_bss_1B28.unk4 = 1;
}
}

__declspec(section ".ctors") extern void* const fn_27_8D794_ctor = (void*)fn_27_8D794;
