void operator delete(void*);
extern "C" {
void* fn_101_5D14(void*, short);
extern unsigned char lbl_27_bss_1CC[];
}

extern "C" void* fn_101_15EA4(void* object, short deleting) {
    if (object != 0) {
        fn_101_5D14(object, static_cast<short>(0));
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}

// These are the original null mediator defaults, including its empty callbacks.
extern "C" bool fn_101_15F00(void*) { return true; }
extern "C" void fn_101_15F08(void*) {}
extern "C" unsigned int fn_101_15F0C(void*) { return 0; }
extern "C" unsigned int fn_101_15F14(void*) { return 0; }
extern "C" unsigned int fn_101_15F1C(void*) { return 0; }
extern "C" unsigned int fn_101_15F24(void*) { return 0; }
extern "C" void fn_101_15F2C(void*) {}
extern "C" void* fn_101_15F30(void*) { return lbl_27_bss_1CC; }
