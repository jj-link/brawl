#pragma force_active on
extern "C" {
void* fn_98_54BC(void*, short);
void* __dl__FPv(void*);

void* fn_98_545C(void* object, short deleting) {
    if (object) {
        fn_98_54BC(static_cast<char*>(object) + 4, static_cast<short>(-1));
        if (deleting > 0) __dl__FPv(object);
    }
    return object;
}
}
