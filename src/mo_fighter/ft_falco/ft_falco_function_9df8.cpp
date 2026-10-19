#pragma force_active on
struct Obj;

extern "C" {
extern signed char lbl_108_bss_194;
extern Obj lbl_108_bss_198;
extern unsigned char lbl_108_bss_17C[];
void fn_27_197E44(Obj* self);
void fn_27_197E54(void* self, int flags);
void* __register_global_object(void* object, void* destructor, void* chain);
}

extern "C" void* fn_108_9DF8() {
    if (lbl_108_bss_194 == 0) {
        fn_27_197E44(&lbl_108_bss_198);
        __register_global_object(&lbl_108_bss_198, (void*)fn_27_197E54, (void*)lbl_108_bss_17C);
        lbl_108_bss_194 = 1;
    }
    return &lbl_108_bss_198;
}
