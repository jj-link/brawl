#pragma force_active on
extern "C" {
void* fn_116_163C8(void* object, short deleting);
void* fn_116_16AA0(void* object, short deleting);
void __dl__FPv(void*);

void* fn_116_16A30(void* object, short deleting) {
    if (object != 0) {
        fn_116_163C8(static_cast<unsigned char*>(object) + 0x8798, static_cast<short>(-1));
        fn_116_16AA0(static_cast<unsigned char*>(object) + 4, static_cast<short>(-1));
        if (deleting > 0) operator delete(object);
    }
    return object;
}
}
