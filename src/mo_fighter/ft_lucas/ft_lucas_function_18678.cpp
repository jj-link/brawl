#pragma force_active on
extern "C" void* fn_114_57E0(void* object, short deleting);
extern "C" void fn_114_186E4(void* object, short deleting);
extern "C" void __dl__FPv(void* object);

extern "C" void* fn_114_18678(void* object, short deleting) {
    if (object != 0) {
        fn_114_57E0(static_cast<char*>(object) + 0x5E94, -1);
        fn_114_186E4(static_cast<char*>(object) + 4, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
