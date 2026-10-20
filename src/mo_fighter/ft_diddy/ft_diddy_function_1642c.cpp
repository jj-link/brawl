#pragma force_active on
void operator delete(void*);

extern "C" {
void* fn_115_2190(void*, short);
void* fn_115_222C(void*, short);
void* fn_115_226C(void*, short);
void* fn_27_C7770(void*, short);
}

extern "C" void* fn_115_1642C(void* object, short deleting) {
    if (object != 0) {
        fn_115_2190((char*)object + 0xdc, -1);
        fn_115_222C((char*)object + 0xc0, -1);
        fn_115_226C((char*)object + 0x14, -1);
        if (object != 0) {
            fn_27_C7770(object, -1);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
