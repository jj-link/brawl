#pragma force_active on
void operator delete(void*);

extern "C" {
void* fn_116_25718(void*, short);
void* fn_116_25A44(void*, short);

void* fn_116_256A8(void* object, short deleting) {
    if (object != 0) {
        fn_116_25718(static_cast<unsigned char*>(object) + 0x18C8, -1);
        fn_116_25A44(object, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
}
