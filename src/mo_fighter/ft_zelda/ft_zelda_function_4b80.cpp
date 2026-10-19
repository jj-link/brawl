#pragma force_active on
extern "C" void fn_104_3480(void*, short);
extern "C" void* fn_104_4BEC(void* object, short deleting);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_104_4B80(void* object, short deleting) {
    if (object != 0) {
        unsigned char* member = static_cast<unsigned char*>(object);
        fn_104_3480(member + 0x20E8, -1);
        fn_104_4BEC(member + 0x4, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
