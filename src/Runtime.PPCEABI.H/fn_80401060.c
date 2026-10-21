#pragma force_active on
int fn_804035C4(void* buffer);
int fn_804035BC(void* buffer);
int fn_804035B4(void* buffer);

extern int lbl_80599F48[];

int TRKInitializeEventQueue(void) {
    fn_804035C4(&lbl_80599F48[0]);
    fn_804035BC(&lbl_80599F48[0]);
    lbl_80599F48[1] = 0;
    lbl_80599F48[2] = 0;
    lbl_80599F48[9] = 0x100;
    fn_804035B4(&lbl_80599F48[0]);
    return 0;
}
