#pragma force_active on
extern "C" {
void fn_112_5480(void*, short);
void fn_112_15554(void*, short);
void __dl__FPv(void*);

void* fn_112_154E4(void* object, short deleting) {
    if (object != 0) {
        fn_112_5480(static_cast<char*>(object) + 0x10000 - 0x4fb8, static_cast<short>(-1));
        fn_112_15554(static_cast<char*>(object) + 4, static_cast<short>(-1));
        if (deleting > 0) __dl__FPv(object);
    }
    return object;
}
}
