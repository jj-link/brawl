#pragma force_active on
extern "C" {
void fn_100_5B74(void*, short);
void fn_100_3FB4(void*, short);
void __dl__FPv(void*);
}

extern "C" void* fn_100_5B08(void* object, short deleting) {
    if (object != 0) {
        char* storage = static_cast<char*>(object);
        fn_100_5B74(storage + 0x24, -1);
        fn_100_3FB4(object, -1);
        if (deleting > 0)
            __dl__FPv(object);
    }
    return object;
}
