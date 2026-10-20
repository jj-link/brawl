#pragma force_active on
void operator delete(void*);
extern "C" void* fn_27_1A15B8(void*, short);
extern "C" void fn_117_4D4C(void* object, short deleting);

extern "C" void* fn_117_4CD4(void* object, short deleting) {
    if (object != 0) {
        fn_27_1A15B8(static_cast<unsigned char*>(object) + 0x2FC, -1);
        if (object != 0) {
            fn_117_4D4C(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
