#pragma force_active on
void operator delete(void*);
extern "C" void* fn_96_2E74(void* object, short deleting);
extern "C" void* __dt__20soResourceModuleImplFv(void* object, short deleting);

extern "C" void* fn_96_2ED4(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        __dt__20soResourceModuleImplFv(storage + 0xc, -1);
        fn_96_2E74(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
