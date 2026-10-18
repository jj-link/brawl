#pragma force_active on
typedef unsigned char u8;

struct Obj1994 {
    u8 flag : 1;
    u8 rest : 7;
    int val;
    u8 pad[0x10];
    void *vt;
};

extern "C" {
extern signed char lbl_27_bss_1990;
extern Obj1994 lbl_27_bss_1994;
extern u8 lbl_27_bss_1040[0xC];
extern u8 lbl_27_data_B310[0xC];
extern void fn_27_7D898(void);
extern void *__register_global_object(void *object, void *destructor, void *chain);

void *fn_27_86268(void)
{
    if (lbl_27_bss_1990 == 0) {
        lbl_27_bss_1994.flag = 0;
        lbl_27_bss_1994.vt = lbl_27_data_B310;
        lbl_27_bss_1994.val = 0;
        __register_global_object(&lbl_27_bss_1994, (void *)fn_27_7D898, lbl_27_bss_1040);
        lbl_27_bss_1990 = 1;
    }
    return &lbl_27_bss_1994;
}
}
