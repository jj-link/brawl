#pragma force_active on
extern "C" {
void* fn_27_1A75E4(void*, short);
void* __dl__FPv(void*);

void* fn_91_2EE8(void* object, short deleting) {
    if (object != 0) {
        fn_27_1A75E4(object, static_cast<short>(-1));
        if (deleting > 0) operator delete(object);
    }
    return object;
}
}
