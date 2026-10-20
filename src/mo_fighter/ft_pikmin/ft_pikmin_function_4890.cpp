#pragma force_active on
void operator delete(void*);
extern "C" void* fn_113_D114(void*, short);
extern "C" void* fn_113_2AAC(void*, short);
extern "C" void* fn_113_2B5C(void*, short);

extern "C" void* fn_113_4890(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_113_D114(storage + 0xE0, -1);
        fn_113_2AAC(storage + 0x30, -1);
        fn_113_2B5C(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
