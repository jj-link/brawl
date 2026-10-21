#pragma force_active on
extern "C" void fn_8015C144(void* p);
extern "C" void fn_8015BFB4(void* p, void* q);

extern "C" void fn_8005BF1C(void* self, void* arg) {
    char* obj = *(char**)((char*)self + 0x24);
    if (obj != 0) {
        fn_8015C144(obj + 0x10);
        fn_8015BFB4(obj + 0x4, arg);
    }
}
