#pragma force_active on
void operator delete(void*);
extern "C" void* fn_120_22A0(void*, short);
extern "C" void* fn_120_21C4(void*, short);

extern "C" void* fn_120_133F4(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_120_22A0(storage + 0x50, -1);
        fn_120_21C4(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
