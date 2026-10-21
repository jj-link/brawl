#pragma force_active on
extern "C" {
extern int lbl_805A00EC;
extern unsigned char lbl_804977F0[16];

void __dt__14gfFileIOHandleFv(void*, int);
void __register_global_object(void*, void*, void*);

void fn_800568A8() {
    lbl_805A00EC = 0;
    __register_global_object(&lbl_805A00EC, (void*)__dt__14gfFileIOHandleFv, lbl_804977F0);
}
}

__declspec(section ".ctors") extern void* const fn_800568A8_ctor = (void*)fn_800568A8;
