#pragma force_active on
extern "C" {
void* fn_98_B920(void*, short);
void __dl__FPv(void*);

void* fn_98_B980(void* object, short deleting) {
    if (object) {
        fn_98_B920(static_cast<char*>(object) + 8, short(-1));
        if (deleting > 0) __dl__FPv(object);
    }
    return object;
}
}
