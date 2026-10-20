#pragma force_active on
void operator delete(void*);
extern "C" void* __dt__17soModelModuleImplFv(void*, short);
extern "C" void* fn_107_83D4(void* object, short deleteFlag);
extern "C" void* fn_27_19A83C(void* object, short deleteFlag);

extern "C" void* fn_107_835C(void* object, short deleting) {
    if (object != 0) {
        __dt__17soModelModuleImplFv(static_cast<unsigned char*>(object) + 0x1F4, -1);
        fn_107_83D4(static_cast<unsigned char*>(object) + 0x1AC, -1);
        fn_27_19A83C(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
