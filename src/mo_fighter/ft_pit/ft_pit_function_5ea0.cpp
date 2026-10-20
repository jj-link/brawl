#pragma force_active on
extern "C" void fn_27_1A18A0(void*, short);
extern "C" void fn_112_5F18(void*, short);
void operator delete(void*);

extern "C" void* fn_112_5EA0(void* object, short deleting) {
    if (object != 0) {
        fn_27_1A18A0(static_cast<unsigned char*>(object) + 0x354, -1);
        if (object != 0) {
            fn_112_5F18(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
