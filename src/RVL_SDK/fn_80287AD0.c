#pragma force_active on
extern float lbl_80532540[4];
extern float lbl_80532550[4];

void fn_80287AD0(void) {
    lbl_80532550[0] = lbl_80532540[0];
    lbl_80532550[1] = lbl_80532540[1];
    lbl_80532550[2] = lbl_80532540[2];
    lbl_80532550[3] = lbl_80532540[3];
}

__declspec(section ".ctors") extern void* const fn_80287AD0_ctor = (void*)fn_80287AD0;
