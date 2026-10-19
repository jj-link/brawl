#pragma force_active on
extern "C" {
void fn_123_1F28(void*, short);
void* fn_123_3CD8(void*, short);
void __dl__FPv(void*);
}

extern "C" void* fn_123_4ED4(void* object, short deleting) {
    if (object != 0) {
        fn_123_1F28(static_cast<unsigned char*>(object) + 0x20, 0);
        fn_123_3CD8(object, 0);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
