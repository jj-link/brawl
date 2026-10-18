#pragma force_active on
void operator delete(void*);

extern "C" {
void* fn_27_10424(void*, short);
void __dl__FPv(void*);
}

extern "C" void* fn_101_20674(void* object, short deleting) {
    if (object != 0) {
        fn_27_10424(static_cast<unsigned char*>(object) + 4, static_cast<short>(-1));
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
