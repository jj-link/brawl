#pragma force_active on
extern "C" {
void* fn_94_2158(void*, short);
void* fn_94_21F4(void*, short);
void* fn_94_2234(void*, short);
void* fn_27_C7770(void*, short);
void __dl__FPv(void*);
}

extern "C" void* fn_94_13ABC(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_94_2158(members + 0xDC, memberDeleting);
        fn_94_21F4(members + 0xC0, memberDeleting);
        fn_94_2234(members + 0x14, memberDeleting);
        if (object != 0) {
            fn_27_C7770(object, memberDeleting);
        }
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
