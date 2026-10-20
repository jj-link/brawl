#pragma force_active on
extern "C" {
extern char lbl_27_data_0[];
extern char lbl_27_bss_8F8[];
struct S { char p[0x1c]; void* m1c; char p2[4]; char m24; char m25; char p3[10]; void* m30; };
void fn_27_70(S* s) {
    s->m30 = lbl_27_data_0;
    s->m1c = lbl_27_bss_8F8;
    s->m24 = 0;
    s->m25 = 0;
}
}
