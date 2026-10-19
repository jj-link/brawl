#pragma force_active on
extern "C" void fn_27_338B24(void*, void*);
extern "C" void fn_27_BEB00(void*);

extern "C" void fn_27_338868(void* object, void* arg) {
    fn_27_338B24(arg, (char*)object + 4);
    fn_27_BEB00((char*)object + 0x14);
}
