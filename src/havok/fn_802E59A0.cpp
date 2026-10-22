#pragma force_active on
typedef unsigned int u32;

extern "C" {
extern void* fn_802E5598(void);
extern void* fn_802E5608(void* arg);
extern void fn_802E5564(void);
extern void fn_802E5584(void);
extern void fn_802E55D4(void);
extern void fn_802E55F4(void);
extern char lbl_80413148[];
extern u32 lbl_80533108[4];
extern u32 lbl_80533118[4];

void fn_802E59A0(void) {
    void* temp_r3;

    temp_r3 = fn_802E5598();
    lbl_80533108[0] = (u32)lbl_80413148;
    lbl_80533108[1] = (u32)fn_802E5564;
    lbl_80533108[2] = (u32)fn_802E5584;
    lbl_80533108[3] = (u32)temp_r3;
    temp_r3 = fn_802E5608(temp_r3);
    lbl_80533118[0] = (u32)(lbl_80413148 + 0x17);
    lbl_80533118[1] = (u32)fn_802E55D4;
    lbl_80533118[2] = (u32)fn_802E55F4;
    lbl_80533118[3] = (u32)temp_r3;
}
}

__declspec(section ".ctors") extern void* const fn_802E59A0_ctor = (void*)fn_802E59A0;
