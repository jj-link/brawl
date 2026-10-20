#pragma force_active on
extern "C" {
void* fn_126_2000(void* self, short flags);
void* fn_126_209C(void* ptr, short count);
void* fn_126_20DC(void* object, short deleting);
void* fn_27_C7770(void*, short);
void __dl__FPv(void*);
}

extern "C" void* fn_126_24BC(void* object, short deleting) {
    if (object != 0) {
        unsigned char* ptr = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_126_2000(ptr + 0xDC, memberDeleting);
        fn_126_209C(ptr + 0xC0, memberDeleting);
        fn_126_20DC(ptr + 0x14, memberDeleting);
        if (object != 0) {
            fn_27_C7770(object, memberDeleting);
        }
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
