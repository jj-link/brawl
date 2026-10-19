#pragma force_active on
void operator delete(void*);
extern "C" void* fn_120_4964(void*, short);
extern "C" void* fn_120_49C4(void*, short);

extern "C" void* fn_120_48F8(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_120_4964(storage + 0x24, -1);
        fn_120_49C4(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
