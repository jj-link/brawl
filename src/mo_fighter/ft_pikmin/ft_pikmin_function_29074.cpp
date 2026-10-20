#pragma force_active on
void operator delete(void*);
extern "C" void* fn_113_29FD0(void*, short);
extern "C" void* fn_113_2AAC(void*, short);
extern "C" void* fn_113_2B5C(void*, short);

extern "C" void* fn_113_29074(void* object, short deleting) {
    if (object != 0) {
        fn_113_29FD0(static_cast<unsigned char*>(object) + 0xE0, -1);
        fn_113_2AAC(static_cast<unsigned char*>(object) + 0x30, -1);
        fn_113_2B5C(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
