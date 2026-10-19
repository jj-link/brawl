#pragma force_active on
void operator delete(void*);
extern "C" void* fn_104_22AC(void*, short);
extern "C" void* fn_104_21D0(void*, short);

extern "C" void* fn_104_38E0(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_104_22AC(storage + 0x50, -1);
        fn_104_21D0(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
