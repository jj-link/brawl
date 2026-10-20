#pragma force_active on
extern "C" void fn_104_18DB0(void* object, short deleting);
extern "C" void fn_104_192DC(void* object, short deleting);
extern "C" void operator delete(void*);

extern "C" void* fn_104_18D38(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_104_18DB0(storage + 0x5dc0, -1);
        if (object != 0) {
            fn_104_192DC(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
