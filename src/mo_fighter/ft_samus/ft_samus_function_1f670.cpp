#pragma force_active on
void operator delete(void*);

extern "C" {
void* fn_94_2158(void* object, short shouldDelete);
void* fn_94_21F4(void* p, short n);
void* fn_94_153D8(void* p, short flag);
void* fn_27_C7770(void* object, short shouldDelete);
}

extern "C" void* fn_94_1F670(void* object, short deleting) {
    if (object != 0) {
        fn_94_2158((char*)object + 0x50, -1);
        fn_94_21F4((char*)object + 0x34, -1);
        fn_94_153D8((char*)object + 0x14, -1);
        if (object != 0) {
            fn_27_C7770(object, -1);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
