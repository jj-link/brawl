#pragma force_active on
extern "C" void fn_11_275C(void*);
extern "C" void fn_11_722C(void*);
extern "C" void fn_11_2748(void* p) {
    if (*(unsigned int*)((char*)p + 0x40) <= 2) {
        fn_11_275C(p);
    } else {
        fn_11_722C(p);
    }
}
