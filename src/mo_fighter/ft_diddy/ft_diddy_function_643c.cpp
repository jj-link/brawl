#pragma force_active on
extern "C" void* __dt__20soResourceModuleImplFv(void* object, short deleting);
extern "C" void* fn_115_3D94(void* object, short deleting);
void operator delete(void*);

extern "C" void* fn_115_643C(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        __dt__20soResourceModuleImplFv(storage + 0xC, -1);
        if (object != 0) {
            fn_115_3D94(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
