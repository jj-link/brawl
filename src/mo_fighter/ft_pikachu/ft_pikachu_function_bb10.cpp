#pragma force_active on
extern "C" {
void* fn_98_BAB0(void*, short);
void __dl__FPv(void*);

void* fn_98_BB10(void* object, short deleting) {
    if (object) {
        fn_98_BAB0(static_cast<char*>(object) + 8, short(-1));
        if (deleting > 0) __dl__FPv(object);
    }
    return object;
}
}
