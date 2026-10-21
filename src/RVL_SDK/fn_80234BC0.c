#pragma force_active on
typedef signed int s32;

extern void fn_80230450(void);
extern void fn_80230454(void);
extern s32 fn_8023A5A4(void);

s32 fn_80234BC0(void) {
    s32 temp_r31;

    fn_80230450();
    temp_r31 = fn_8023A5A4();
    fn_80230454();
    return temp_r31;
}
