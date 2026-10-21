#pragma force_active on
extern "C" {
int fn_802D4D10(void);
void fn_802D4CE4(void* arg0);
void fn_802D4CFC(void* arg0);
extern char lbl_804109E0[];
extern void* lbl_80532858[4];
}

extern "C" void fn_802D4DBC(int arg0) {
    int temp_r3;

    temp_r3 = fn_802D4D10();
    lbl_80532858[0] = lbl_804109E0;
    lbl_80532858[1] = (void*)fn_802D4CE4;
    lbl_80532858[2] = (void*)fn_802D4CFC;
    lbl_80532858[3] = (void*)temp_r3;
}

__declspec(section ".ctors") extern void* const fn_802D4DBC_ctor = (void*)fn_802D4DBC;
