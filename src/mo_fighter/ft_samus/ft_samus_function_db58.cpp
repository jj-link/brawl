#pragma force_active on
extern "C" void* fn_94_DAF8(void* object, short deleting);
extern "C" void* fn_94_D9C4(void* object, short deleting);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_94_DB58(void* object, short deleting) {
    if (object != 0) {
        fn_94_DAF8(static_cast<char*>(object) + 0x204, -1);
        if (object != 0) {
            fn_94_D9C4(object, 0);
        }
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
