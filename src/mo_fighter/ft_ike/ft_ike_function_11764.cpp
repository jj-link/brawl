#pragma force_active on
void operator delete(void* p);
extern "C" void* __dt__20soResourceModuleImplFv(void* object, short deleting);
extern "C" void* fn_119_55D0(void* p, short flag);

extern "C" void* fn_119_11764(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        __dt__20soResourceModuleImplFv(storage + 0x18, -1);
        if (object != 0) {
            fn_119_55D0(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
