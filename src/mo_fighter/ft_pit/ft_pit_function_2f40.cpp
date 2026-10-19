#pragma force_active on
void operator delete(void*);

extern "C" {
void* fn_27_10424(void*, short);
void* fn_27_19A97C(void*, short);
}

extern "C" void* fn_112_2F40(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_27_10424(members + 0x7C, memberDeleting);
        if (object != 0) {
            fn_27_19A97C(object, memberDeleting);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
