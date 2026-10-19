#pragma force_active on
extern "C" void* fn_114_52CC(void* object, short deleting);
extern "C" void* fn_114_5BCC(void* object, short deleting);
extern "C" void __dl__FPv(void* p);

extern "C" void* fn_114_525C(void* object, short deleting) {
    if (object != 0) {
        char* p = static_cast<char*>(object);
        p += 0x10000;
        p -= 0x21E0;
        fn_114_52CC(p, -1);
        fn_114_5BCC(static_cast<char*>(object) + 4, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
