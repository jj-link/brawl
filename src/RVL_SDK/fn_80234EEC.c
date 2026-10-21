#pragma force_active on
typedef unsigned char u8;
typedef int s32;

void fn_80230450(void);
void fn_80230454(void);
u8 fn_80239DCC(s32);

u8 fn_80234EEC(s32 arg0) {
    u8 temp_r31;

    fn_80230450();
    temp_r31 = fn_80239DCC(arg0);
    fn_80230454();
    return (u8)(temp_r31 == 0);
}
