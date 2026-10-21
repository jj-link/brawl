#pragma force_active on
extern "C" {
int fn_802E7904(void);
void fn_802E7878(void);
void fn_802E78F0(void);
}
extern char lbl_80413210[];
extern int lbl_80533190[4];

extern "C" {
void fn_802E83C8(void) {
    int temp_r3;

    temp_r3 = fn_802E7904();
    lbl_80533190[0] = (int)(lbl_80413210 + 0x28);
    lbl_80533190[1] = (int)fn_802E7878;
    lbl_80533190[2] = (int)fn_802E78F0;
    lbl_80533190[3] = temp_r3;
}
}

__declspec(section ".ctors") extern void* const fn_802E83C8_ctor = (void*)fn_802E83C8;
