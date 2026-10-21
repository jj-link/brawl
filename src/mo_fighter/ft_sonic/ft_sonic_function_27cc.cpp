#pragma force_active on
void operator delete(void*);

extern "C" {
void* fn_123_216C(void*, short);
void* fn_123_2208(void*, short);
void* fn_123_2248(void*, short);
void* fn_123_2864(void*, short);
void fn_27_1A66F4(void*, short);
}

extern "C" void* fn_123_27CC(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_123_216C(members + 0xa1c, memberDeleting);
        fn_123_2208(members + 0xa00, memberDeleting);
        fn_123_2248(members + 0x954, memberDeleting);
        fn_123_2864(members + 0x4a8, memberDeleting);
        if (object != 0) {
            fn_27_1A66F4(object, memberDeleting);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
