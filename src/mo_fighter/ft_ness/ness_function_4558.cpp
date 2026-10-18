#pragma force_active on
void operator delete(void*);

extern "C" {
void* fn_27_565F0(void*, short);
void __dl__FPv(void*);
}

extern "C" void* fn_101_4558(void* object, short deleting) {
    if (object != 0) {
        fn_27_565F0(static_cast<unsigned char*>(object) + 0xC,
                    static_cast<short>(-1));
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
