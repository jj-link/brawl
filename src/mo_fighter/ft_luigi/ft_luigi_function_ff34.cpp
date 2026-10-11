extern "C" void* __dt__17soModelModuleImplFv(void*, short);
extern "C" void* fn_27_CBDE8(void*, short);

extern "C" void* fn_99_FF34(void* object, short deleting) {
    if (object) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        int destroyMember = -1;
        __dt__17soModelModuleImplFv(storage + 0x114, destroyMember);
        fn_27_CBDE8(object, destroyMember);
        if (deleting > 0) operator delete(object);
    }
    return object;
}
