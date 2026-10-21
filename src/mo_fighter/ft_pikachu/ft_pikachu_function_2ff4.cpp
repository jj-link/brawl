#pragma force_active on
void operator delete(void*);

extern "C" {
void* fn_27_97968(void*, short);
void* fn_27_1CCCC(void*, short);
void* fn_98_308C(void*, short);
void* fn_98_30E8(void*, short);
void* fn_27_CBF58(void*, short);
}

extern "C" void* fn_98_2FF4(char* object, short deleting) {
    if (object) {
        short memberDeleting = -1;
        fn_27_97968(object + 0x6c, memberDeleting);
        fn_27_1CCCC(object + 0x5c, memberDeleting);
        fn_98_308C(object + 0x50, memberDeleting);
        fn_98_30E8(object + 0x38, memberDeleting);
        if (object) fn_27_CBF58(object, memberDeleting);
        if (deleting > 0) operator delete(object);
    }
    return object;
}
