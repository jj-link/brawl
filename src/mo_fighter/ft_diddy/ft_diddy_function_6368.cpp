#pragma force_active on
void operator delete(void*);
extern "C" void* __dt__17soModelModuleImplFv(void*, short);
extern "C" void* fn_115_63E0(void* object, short deleteFlag);
extern "C" void* fn_27_19A83C(void* member, short deleteFlag);

extern "C" void* fn_115_6368(void* object, short deleteFlag) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        __dt__17soModelModuleImplFv(storage + 0x1F4, -1);
        fn_115_63E0(storage + 0x1AC, -1);
        fn_27_19A83C(object, -1);
        if (deleteFlag > 0) {
            operator delete(object);
        }
    }
    return object;
}
