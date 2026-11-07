#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;
extern u8 fn_80247FFC(unsigned int);
extern char lbl_80529AC8[];
void fn_80236234(u8 *arg0, u8 *arg1) {
    u8 data[2];
    u8 value;
    if (arg1 != 0)
        value = *(u16 *)(arg1 + 6);
    else
        value = arg0[0x16];
    data[1] = value;
    data[0] = 6;
    if (fn_80247FFC(value))
        (*(void (**)(int, u8 *))(lbl_80529AC8 + 0x224))(3, data);
}