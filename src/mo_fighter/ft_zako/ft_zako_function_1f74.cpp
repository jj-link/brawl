#pragma force_active on
void operator delete(void*);

extern "C" {
void* fn_126_2000(void*, short);
void* fn_126_209C(void*, short);
void* fn_126_20DC(void*, short);
void* fn_27_C7770(void*, short);
}

extern "C" void* fn_126_1F74(void* object, short deleting) {
    if (object != 0) {
        short flags = -1;
        unsigned char* members = static_cast<unsigned char*>(object);
        fn_126_2000(members + 0xDC, flags);
        fn_126_209C(members + 0xC0, flags);
        fn_126_20DC(members + 0x14, flags);
        if (object != 0) {
            fn_27_C7770(object, flags);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
