#pragma force_active on
extern "C" {
void* fn_115_2190(void*, short);
void* fn_115_222C(void*, short);
void* fn_115_226C(void*, short);
void* fn_27_C7770(void*, short);
}

void operator delete(void*);

extern "C" void* fn_115_26D8(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_115_2190(members + 0xDC, memberDeleting);
        fn_115_222C(members + 0xC0, memberDeleting);
        fn_115_226C(members + 0x14, memberDeleting);
        if (object != 0) {
            fn_27_C7770(object, memberDeleting);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
