#pragma force_active on
extern char lbl_27_data_20C90[];

struct soWork {
    void* m0;
    void* m4;
    unsigned int m8;
};

extern "C" {
void fn_27_CB5A8(soWork* w)
{
    w->m0 = lbl_27_data_20C90;
    w->m4 = lbl_27_data_20C90 + 0x48;
    w->m8 &= 0x3FF;
}
}
