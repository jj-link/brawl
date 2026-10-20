#pragma force_active on
extern "C" void* fn_95_DA70(void*, short);
extern "C" void* fn_95_D938(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_95_DAD0(void* object, short deleting) {
    if (object != 0) {
        fn_95_DA70(static_cast<char*>(object) + 0x17C, -1);
        if (object != 0) {
            fn_95_D938(object, 0);
        }
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
