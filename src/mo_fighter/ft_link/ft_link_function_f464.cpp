#pragma force_active on
extern "C" {
extern unsigned char lbl_93_bss_15C[];
extern unsigned char lbl_93_bss_150[];

void* fn_93_F4AC(void*);
void* fn_93_F424(void*, short);
void* __register_global_object(void*, void*, void*);

void fn_93_F464() {
    fn_93_F4AC(lbl_93_bss_15C);
    __register_global_object(
        lbl_93_bss_15C,
        (void*)fn_93_F424,
        lbl_93_bss_150
    );
}
}

__declspec(section ".ctors") extern void* const fn_93_F464_ctor = (void*)fn_93_F464;
