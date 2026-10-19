#pragma force_active on
extern "C" void* fn_94_3890(void*, short);
extern "C" void* fn_94_395C(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_94_38F0(void* object, short deleting) {
    if (object != 0) {
        fn_94_3890(static_cast<unsigned char*>(object) + 0x1934, -1);
        fn_94_395C(static_cast<unsigned char*>(object) + 4, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
