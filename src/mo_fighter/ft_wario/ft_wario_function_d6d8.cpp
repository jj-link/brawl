#pragma force_active on

typedef struct DestructorChain DestructorChain;

extern "C" {
void fn_110_D720(void*);
void* fn_110_D698(void*, short);
void* __register_global_object(void*, void*, DestructorChain*);
extern unsigned char lbl_110_bss_1A4[];
extern unsigned char lbl_110_bss_198[];

void fn_110_D6D8(void) {
    fn_110_D720(lbl_110_bss_1A4);
    __register_global_object(
        lbl_110_bss_1A4,
        (void*)fn_110_D698,
        (DestructorChain*)lbl_110_bss_198
    );
}
}

__declspec(section ".ctors") extern void* const fn_110_D6D8_ctor = (void*)fn_110_D6D8;
