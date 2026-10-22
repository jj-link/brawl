#pragma force_active on
extern "C" {

extern void fn_80170224(int* p);
extern void OSRegisterVersion(int version);
extern void __register_global_object(void* obj, void* dtor, void* type_info);
extern void fn_80164738(void);
extern int lbl_80465240[];
extern int lbl_80465484[];
extern int lbl_804653EC[];
extern int lbl_8049EDD8[];
extern int lbl_8049EDC8[];
extern int lbl_8059E870;
extern unsigned char lbl_8059E874;
extern int* lbl_805A04C0;
extern int* lbl_805A04C4;
extern int* lbl_805A04C8;

void fn_80164C88(void) {
    lbl_805A04C0 = lbl_80465240;
    lbl_805A04C4 = lbl_80465484;
    lbl_805A04C8 = lbl_804653EC;
    fn_80170224(lbl_8049EDD8 + 4);
    if (lbl_8059E874) {
        lbl_8059E874 = 0;
        OSRegisterVersion(lbl_8059E870);
    }
    lbl_8049EDD8[0] = 0;
    lbl_8049EDD8[0x1405] = 0;
    ((unsigned char*)lbl_8049EDD8)[0x5064] = 0;
    __register_global_object(lbl_8049EDD8, fn_80164738, lbl_8049EDC8);
}

}

__declspec(section ".ctors") extern void* const fn_80164C88_ctor = (void*)fn_80164C88;
