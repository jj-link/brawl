#pragma force_active on
extern "C" void* fn_114_5D0C(void* object, short deleting);
extern "C" void* fn_114_6380(void* object, short deleting);
extern "C" void __dl__FPv(void* object);

extern "C" void* fn_114_6310(void* object, short deleting) {
    if (object != 0) {
        fn_114_5D0C(static_cast<char*>(object) + 0xE0C8, -1);
        fn_114_6380(static_cast<char*>(object) + 4, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
