#pragma force_active on
typedef struct DestructorChain {
    DestructorChain* next;
    void* destructor;
    void* object;
} DestructorChain;

struct VFTbl;

extern "C" void fn_96_24428(VFTbl*);
extern "C" void* fn_96_243A0(void*, short);
extern "C" void* __register_global_object(void*, void*, DestructorChain*);
extern "C" unsigned char lbl_96_bss_116C[];
extern "C" DestructorChain lbl_96_bss_1160;

extern "C" void fn_96_243E0() {
    fn_96_24428((VFTbl*)lbl_96_bss_116C);
    __register_global_object(lbl_96_bss_116C, (void*)fn_96_243A0, &lbl_96_bss_1160);
}

__declspec(section ".ctors") extern void* const fn_96_243E0_ctor = (void*)fn_96_243E0;
