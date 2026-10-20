#pragma force_active on
extern "C" void* fn_94_2158(void* object, short shouldDelete);
extern "C" void* fn_94_21F4(void* p, short n);
extern "C" void* fn_94_2234(void* object, short count);
extern "C" void* fn_27_C7770(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_94_2470(void* object, short deleting) {
    if (object != 0) {
        short memberDeleting = -1;
        fn_94_2158(static_cast<unsigned char*>(object) + 0xdc, memberDeleting);
        fn_94_21F4(static_cast<unsigned char*>(object) + 0xc0, memberDeleting);
        fn_94_2234(static_cast<unsigned char*>(object) + 0x14, memberDeleting);
        if (object != 0) {
            fn_27_C7770(object, memberDeleting);
        }
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
