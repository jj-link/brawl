#pragma force_active on
extern "C" {
int fn_802DABA0(void);
void fn_802DAB58(void);
void fn_802DAB8C(void);
extern char lbl_804121F0[];
extern unsigned int lbl_80532E50[4];
}

extern "C" void fn_802DBC30(void) {
    int temp_r3 = fn_802DABA0();
    lbl_80532E50[0] = (unsigned int)lbl_804121F0;
    lbl_80532E50[1] = (unsigned int)fn_802DAB58;
    lbl_80532E50[2] = (unsigned int)fn_802DAB8C;
    lbl_80532E50[3] = (unsigned int)temp_r3;
}

__declspec(section ".ctors") extern void* const fn_802DBC30_ctor = (void*)fn_802DBC30;
