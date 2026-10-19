#pragma force_active on
extern "C" void* fn_96_9234(void* object, short deleting);
extern "C" void* fn_96_8F74(void* object, short deleting);
extern "C" void __dl__FPv(void* object);

extern "C" void* fn_96_9294(void* object, short deleting) {
    if (object != 0) {
        fn_96_9234(static_cast<char*>(object) + 0xEF84, -1);
        if (object != 0) {
            fn_96_8F74(object, 0);
        }
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
