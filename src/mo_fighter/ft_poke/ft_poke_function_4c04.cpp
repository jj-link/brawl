#pragma force_active on
extern "C" void* __dt__17soModelModuleImplFv(void*, short);
extern "C" void* fn_27_19A5BC(void*, short);
void operator delete(void*);

extern "C" void* fn_116_4C04(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        __dt__17soModelModuleImplFv(storage + 0x78, -1);
        fn_27_19A5BC(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
