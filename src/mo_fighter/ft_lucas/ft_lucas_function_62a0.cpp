#pragma force_active on
extern "C" void* fn_114_5D0C(void* object, short deleting);
extern "C" void fn_114_6310(void* object, short deleting);
extern "C" void __dl__FPv(void* p);

extern "C" void* fn_114_62A0(char* object, short deleting) {
    if (object != 0) {
        fn_114_5D0C(object + 0xFCE0, -1);
        fn_114_6310(object + 4, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
