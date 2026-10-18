#pragma force_active on
extern "C" void fn_27_2FF758(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_94_33FC(void* object, short deleting) {
    if (object != 0) {
        fn_27_2FF758(static_cast<unsigned char*>(object) + 4, -1);
        if (deleting > 0)
            __dl__FPv(object);
    }
    return object;
}
