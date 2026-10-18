#pragma force_active on
extern "C" {
void fn_100_B5EC(void*, short);
void __dl__FPv(void*);
}

extern "C" void* fn_100_B648(void* object, short mode) {
    if (object) {
        fn_100_B5EC(static_cast<char*>(object) + 4, -1);
        if (mode > 0)
            __dl__FPv(object);
    }
    return object;
}
