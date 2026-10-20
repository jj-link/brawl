#pragma force_active on
struct DestructorChain;

extern "C" void __register_global_object(void*, void*, DestructorChain*);
extern "C" void* fn_27_84298(void*, int);

extern "C" signed char lbl_27_bss_1190;
extern "C" unsigned char lbl_27_bss_1194[];
extern "C" unsigned char lbl_27_bss_E60[];

extern "C" unsigned char* fn_27_834F0() {
    if (lbl_27_bss_1190 == 0) {
        unsigned char* object = lbl_27_bss_1194;
        *reinterpret_cast<int*>(object + 4) = -1;
        *reinterpret_cast<short*>(object + 8) = 0;
        *reinterpret_cast<short*>(object + 10) = -1;
        __register_global_object(
            object,
            reinterpret_cast<void*>(fn_27_84298),
            reinterpret_cast<DestructorChain*>(lbl_27_bss_E60));
        lbl_27_bss_1190 = 1;
    }
    return lbl_27_bss_1194;
}
