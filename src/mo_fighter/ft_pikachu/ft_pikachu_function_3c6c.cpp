#pragma force_active on
extern "C" {
void* fn_27_97968(void*, short);
void* fn_27_1CCCC(void*, short);
void* fn_98_308C(void*, short);
void* fn_27_CBF58(void*, short);
}

void operator delete(void*);

extern "C" void* fn_98_3C6C(void* object, short deleting) {
    if (object != 0) {
        short memberDeleting = -1;
        fn_27_97968((char*)object + 0x58, memberDeleting);
        fn_27_1CCCC((char*)object + 0x48, memberDeleting);
        fn_98_308C((char*)object + 0x3c, memberDeleting);
        if (object != 0) {
            fn_27_CBF58(object, memberDeleting);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
