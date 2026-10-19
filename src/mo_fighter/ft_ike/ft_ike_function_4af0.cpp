#pragma force_active on
extern "C" void fn_27_614C4(void*, short);
extern "C" void fn_27_D3080(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_119_4AF0(void* object, short deleting) {
    if (object != 0) {
        fn_27_614C4(static_cast<unsigned char*>(object) + 0xac, -1);
        if (object != 0) {
            fn_27_D3080(object, -1);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
