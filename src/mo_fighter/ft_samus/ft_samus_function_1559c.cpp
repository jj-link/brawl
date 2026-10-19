#pragma force_active on
void operator delete(void*);
extern "C" void __dt__17soModelModuleImplFv(void*, short);
extern "C" void* fn_27_19A33C(void*, short);

extern "C" void* fn_94_1559C(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        __dt__17soModelModuleImplFv(storage + 0x44, -1);
        fn_27_19A33C(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
