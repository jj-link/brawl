#pragma force_active on
extern "C" void fn_8015C144(void* a, void* b);
extern "C" void fn_8015BFB4(void* a, void* b);

extern "C" void fn_8005C06C(void* self, void* arg) {
    char* obj = *(char**)((char*)self + 0x18);
    if (obj != 0) {
        fn_8015C144(obj + 0x10, arg);
        fn_8015BFB4(obj + 0x4, arg);
    }
}
