#pragma force_active on
extern "C" void* fn_112_40C8(void* object, short deleting);
extern "C" void* fn_112_4EA0(void* object, short deleting);
extern "C" void __dl__FPv(void* object);

extern "C" void* fn_112_4054(void* object, short deleting) {
    if (object != 0) {
        fn_112_40C8(static_cast<char*>(object) + 0x180B4, -1);
        fn_112_4EA0(object, 0);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
