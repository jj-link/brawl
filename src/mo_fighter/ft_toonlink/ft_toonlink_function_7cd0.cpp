#pragma force_active on
extern "C" void* fn_121_7C54(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_121_7CD0(void* object, short deleting) {
    if (object) {
        fn_121_7C54(object, 0);
        if (deleting > 0)
            __dl__FPv(object);
    }
    return object;
}
