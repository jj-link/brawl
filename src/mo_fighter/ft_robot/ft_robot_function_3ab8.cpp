#pragma force_active on
void operator delete(void*);
extern "C" void* fn_120_9EE4(void*, short);
extern "C" void* fn_120_3B30(void*, short);
extern "C" void* fn_120_3B90(void*, short);

extern "C" void* fn_120_3AB8(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_120_9EE4(storage + 0xE0, -1);
        fn_120_3B30(storage + 0x30, -1);
        fn_120_3B90(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
