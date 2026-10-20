#pragma force_active on
typedef struct
{
    unsigned int unk[4];
} bss_46C_t;

extern bss_46C_t lbl_27_bss_46C;

extern "C" bss_46C_t* fn_27_2DA284()
{
    return &lbl_27_bss_46C;
}
