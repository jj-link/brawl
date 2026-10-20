#pragma force_active on
void operator delete(void*);
extern "C" void* fn_104_21D0(void*, short);
extern "C" void* fn_104_226C(void*, short);
extern "C" void* fn_104_22AC(void*, short);
extern "C" void* fn_27_C7770(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_104_237A0(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_104_21D0(storage + 0xDC, -1);
        fn_104_226C(storage + 0xC0, -1);
        fn_104_22AC(storage + 0x14, -1);
        if (object != 0) {
            fn_27_C7770(object, -1);
        }
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
