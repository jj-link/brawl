#pragma force_active on
#pragma opt_propagation off
#pragma scheduling off
struct Reg { void* a; void* b; void* c; };
struct KoopaGlobals {
Reg registration0;
unsigned char object0[4];
Reg registration1;
unsigned char object1[4];
Reg registration2;
unsigned char object2[4];
Reg registration3;
unsigned char object3[4];
Reg registration4;
unsigned char object4[4];
};
extern "C" {
extern KoopaGlobals lbl_102_bss_260;
void fn_102_F474(void*);
void fn_102_F484(void*);
void fn_102_F494(void*);
void fn_102_F4A4(void*);
void fn_102_F4B4(void*);
void fn_102_F27C();
void fn_102_F2BC();
void fn_102_F2FC();
void fn_102_F33C();
void fn_102_F37C();
void __register_global_object(void*, void*, void*);

void fn_102_F3BC() {
    Reg KoopaGlobals::* r = &KoopaGlobals::registration0;
    fn_102_F474(lbl_102_bss_260.object0);
    __register_global_object(lbl_102_bss_260.object0, (void*)fn_102_F37C, &(lbl_102_bss_260.*r));
    fn_102_F484(lbl_102_bss_260.object1);
    __register_global_object(lbl_102_bss_260.object1, (void*)fn_102_F33C, &lbl_102_bss_260.registration1);
    fn_102_F494(lbl_102_bss_260.object2);
    __register_global_object(lbl_102_bss_260.object2, (void*)fn_102_F2FC, &lbl_102_bss_260.registration2);
    fn_102_F4A4(lbl_102_bss_260.object3);
    __register_global_object(lbl_102_bss_260.object3, (void*)fn_102_F2BC, &lbl_102_bss_260.registration3);
    fn_102_F4B4(lbl_102_bss_260.object4);
    __register_global_object(lbl_102_bss_260.object4, (void*)fn_102_F27C, &lbl_102_bss_260.registration4);
}
}

__declspec(section ".ctors") extern void* const fn_102_F3BC_ctor = (void*)fn_102_F3BC;
