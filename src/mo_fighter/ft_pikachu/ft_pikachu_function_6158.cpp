#pragma force_active on
extern "C" {
void* fn_27_D2904(void*, short);
void* fn_98_61D0(void*, short);
void __dl__FPv(void*);
}

extern "C" void* fn_98_6158(void* object, short deleting) {
    if (object) {
        fn_27_D2904(static_cast<unsigned char*>(object) + 0xB4, short(-1));
        if (object) fn_98_61D0(object, short(0));
        if (deleting > 0) __dl__FPv(object);
    }
    return object;
}
