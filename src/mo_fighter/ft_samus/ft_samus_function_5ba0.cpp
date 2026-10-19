#pragma force_active on
extern "C" void fn_94_5C0C(void*, short);
extern "C" void fn_94_4AEC(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_94_5BA0(void* object, short deleting) {
    if (object != 0) {
        fn_94_5C0C(static_cast<unsigned char*>(object) + 0x24, -1);
        fn_94_4AEC(object, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
