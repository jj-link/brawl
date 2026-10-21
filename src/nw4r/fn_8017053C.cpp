extern "C" {
#pragma force_active on
extern int *lbl_805A04D0;
extern int *lbl_805A04D4;
extern int *lbl_805A04D8;
extern int *lbl_805A04DC;
extern int *lbl_805A04E0;
extern int *lbl_805A04E4;
extern int *lbl_805A04E8;
extern int lbl_804653F8[];
extern int lbl_80465408[];
extern int lbl_80465418[];
extern int lbl_80465428[];
extern int lbl_80465438[];
extern int lbl_80465448[];
extern int lbl_80465458[];

void fn_8017053C(void) {
    lbl_805A04D0 = lbl_80465418;
    lbl_805A04D4 = lbl_80465408;
    lbl_805A04D8 = lbl_80465438;
    lbl_805A04DC = lbl_80465428;
    lbl_805A04E0 = lbl_80465448;
    lbl_805A04E4 = lbl_80465458;
    lbl_805A04E8 = lbl_804653F8;
}
}

__declspec(section ".ctors") extern void* const fn_8017053C_ctor = (void*)fn_8017053C;
