#pragma force_active on
extern "C" {
void fn_801B77F8(void);
void fn_801B79A8(void);
void fn_801BB188(void);
void fn_801BB37C(void);
void fn_801BD6A0(void);
void fn_801BD838(void);
void fn_801C2C04(void);
void fn_801C2D48(void);
void fn_801CC2E4(void);
void fn_801CC550(void);
void fn_801CFA14(void);
void fn_801CFFDC(void);
void fn_801D02EC(void*);
void fn_801D2AD0(void);
void fn_801D2C94(void);
extern char lbl_804C2010[];
extern unsigned char lbl_805A05F8;

void fn_801CC228(void) {
    if (lbl_805A05F8 != 0) {
        fn_801CC2E4();
        fn_801CC550();
        fn_801CFA14();
        fn_801CFFDC();
        fn_801D02EC(lbl_804C2010);
        fn_801C2C04();
        fn_801C2D48();
        fn_801BD6A0();
        fn_801BD838();
        fn_801D2AD0();
        fn_801D2C94();
        fn_801BB188();
        fn_801BB37C();
        fn_801B77F8();
        fn_801B79A8();
        lbl_805A05F8 = 0;
    }
}
}
