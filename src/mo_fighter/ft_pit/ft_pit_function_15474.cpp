#pragma force_active on
extern "C" {
void fn_112_5480(void* object, short deleting);
void fn_112_154E4(void* object, short deleting);
void __dl__FPv(void*);

void* fn_112_15474(void* object, short deleting) {
    if (object != 0) {
        fn_112_5480(static_cast<unsigned char*>(object) + 0xD388, static_cast<short>(-1));
        fn_112_154E4(static_cast<unsigned char*>(object) + 4, static_cast<short>(-1));
        if (deleting > 0) operator delete(object);
    }
    return object;
}
}
