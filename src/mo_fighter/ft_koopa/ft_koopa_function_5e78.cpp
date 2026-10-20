#pragma force_active on
void operator delete(void*);
extern "C" void* __dt__20soResourceModuleImplFv(void* object, short deleting);
extern "C" void* fn_102_5EF0(void* self, short flag);

extern "C" void* fn_102_5E78(void* object, short deleting) {
    if (object != 0) {
        __dt__20soResourceModuleImplFv(static_cast<unsigned char*>(object) + 0xC, -1);
        if (object != 0) {
            fn_102_5EF0(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
