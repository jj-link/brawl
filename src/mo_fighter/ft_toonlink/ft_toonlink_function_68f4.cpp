#pragma force_active on
extern "C" void* __dt__20soResourceModuleImplFv(void*, short);
extern "C" void fn_121_285C(void* ptr, short count);
void operator delete(void*);

extern "C" void* fn_121_68F4(void* object, short deleting) {
    unsigned char* storage;
    if (object != 0) {
        storage = static_cast<unsigned char*>(object);
        __dt__20soResourceModuleImplFv(storage + 0x18, -1);
        if (object != 0) {
            fn_121_285C(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
