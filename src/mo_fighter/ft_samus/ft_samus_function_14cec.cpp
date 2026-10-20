#pragma force_active on
void operator delete(void*);
extern "C" void* __dt__20soResourceModuleImplFv(void*, short);
extern "C" void* fn_94_4D20(void* p, short flag);

extern "C" void* fn_94_14CEC(void* object, short deleting) {
    if (object != 0) {
        __dt__20soResourceModuleImplFv(static_cast<unsigned char*>(object) + 0x18, -1);
        if (object != 0) {
            fn_94_4D20(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
