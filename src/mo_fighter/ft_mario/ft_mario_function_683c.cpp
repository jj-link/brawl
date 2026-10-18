#pragma force_active on
extern "C" {
void* fn_27_6880C(void*, short);
void __dl__FPv(void*);

void* fn_91_683C(void* object, short deleting) {
    if (object != 0) {
        fn_27_6880C(static_cast<unsigned char*>(object) + 4, static_cast<short>(-1));
        if (deleting > 0) __dl__FPv(object);
    }
    return object;
}
}
