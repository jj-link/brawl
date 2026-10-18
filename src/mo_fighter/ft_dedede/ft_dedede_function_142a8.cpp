#pragma force_active on
void operator delete(void*);
extern "C" void* fn_27_1A262C(void*, short);

extern "C" void* fn_117_142A8(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_27_1A262C(storage + 0x10, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
