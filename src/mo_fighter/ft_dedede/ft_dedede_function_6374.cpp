#pragma force_active on
void operator delete(void*);
extern "C" void __dt__17soModelModuleImplFv(void*, short);
extern "C" void* fn_117_63EC(void*, short);
extern "C" void* fn_27_19A83C(void*, short);

extern "C" void* fn_117_6374(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        __dt__17soModelModuleImplFv(members + 0x1F4, memberDeleting);
        fn_117_63EC(members + 0x1AC, memberDeleting);
        fn_27_19A83C(object, memberDeleting);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
