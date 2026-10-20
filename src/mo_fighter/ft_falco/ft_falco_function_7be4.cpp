#pragma force_active on
void operator delete(void*);
extern "C" void* __dt__17soModelModuleImplFv(void*, short);
extern "C" void* fn_108_7C5C(void* object, short deleteFlag);
extern "C" void* fn_27_19A47C(void* ptr, short deleteFlag);

extern "C" void* fn_108_7BE4(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        __dt__17soModelModuleImplFv(storage + 0x25C, -1);
        fn_108_7C5C(storage + 0x214, -1);
        fn_27_19A47C(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
