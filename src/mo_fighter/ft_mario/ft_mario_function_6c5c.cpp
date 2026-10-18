#pragma force_active on
extern "C" {
void* fn_91_5D04(void*, short);
void __dl__FPv(void*);

void* fn_91_6C5C(void* object, short deleting) {
    if (object != 0) {
        fn_91_5D04(static_cast<unsigned char*>(object) + 4, static_cast<short>(-1));
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
}
