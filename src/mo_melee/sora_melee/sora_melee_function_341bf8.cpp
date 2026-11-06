#pragma force_active on
#pragma optimization_level 2

extern "C" {

extern char lbl_27_data_8C358;
extern char lbl_27_bss_7E80[0xC];
extern unsigned int lbl_27_bss_7E8C;

void* fn_27_341BB8(void*, int);
void __register_global_object(void*, void*, void*);

}

inline void initialize_and_register(unsigned int value, unsigned int* object,
                                    void* destructor, void* registration) {
    *object = 0;
    *object = value;
    __register_global_object(object, destructor, registration);
}

extern "C" void fn_27_341BF8() {
    initialize_and_register(
        (unsigned int)&lbl_27_data_8C358,
        &lbl_27_bss_7E8C,
        (void*)fn_27_341BB8,
        lbl_27_bss_7E80
    );
}

__declspec(section ".ctors") extern void* const fn_27_341BF8_ctor = (void*)fn_27_341BF8;
