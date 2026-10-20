#pragma force_active on
extern "C" void* fn_115_4E50(void*, short);
extern "C" void* fn_27_1A15B8(void*, short);
void operator delete(void*) __attribute__((nothrow));

extern "C" void* fn_115_4DD8(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_27_1A15B8(storage + 0x2FC, -1);
        if (object != 0) {
            fn_115_4E50(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
