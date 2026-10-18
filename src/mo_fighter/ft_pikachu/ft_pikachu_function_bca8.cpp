#pragma force_active on
extern "C" {
void* fn_98_BC48(void*, short);
void __dl__FPv(void*);

void* fn_98_BCA8(void* object, short deleting) {
    if (object) {
        fn_98_BC48(static_cast<char*>(object) + 8, static_cast<short>(-1));
        if (deleting > 0) __dl__FPv(object);
    }
    return object;
}
}
