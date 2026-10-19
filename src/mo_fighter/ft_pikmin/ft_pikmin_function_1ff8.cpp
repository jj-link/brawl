#pragma force_active on
extern "C" {
void* fn_113_2068(void*, short);
void* fn_113_3694(void*, short);
void __dl__FPv(void*);

void* fn_113_1FF8(void* object, short deleting) {
    if (object != 0) {
        fn_113_2068(static_cast<unsigned char*>(object) + 0x10084, static_cast<short>(-1));
        fn_113_3694(static_cast<unsigned char*>(object) + 4, static_cast<short>(-1));
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
}
