#pragma force_active on
extern "C" void* __dt__17soModelModuleImplFv(void*, short);
extern "C" void* fn_92_6B50(void*, short);
extern "C" void* fn_27_19A83C(void*, short);

extern "C" void* fn_92_6AD8(void* object, short deleting) {
    if (object != 0) {
        __dt__17soModelModuleImplFv(static_cast<unsigned char*>(object) + 0x1F4, -1);
        fn_92_6B50(static_cast<unsigned char*>(object) + 0x1AC, -1);
        fn_27_19A83C(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
