#pragma force_active on
void operator delete(void*);
extern "C" void __dt__20soResourceModuleImplFv(void*, short);
extern "C" void* fn_122_4C3C(void*, short);

extern "C" void* fn_122_A868(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        __dt__20soResourceModuleImplFv(storage + 0xC, -1);
        if (object != 0) {
            fn_122_4C3C(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
