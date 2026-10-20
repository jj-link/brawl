#pragma force_active on
void operator delete(void*);
extern "C" {
void* fn_101_8F9C(void*, short);
void* fn_27_19A83C(void*, short);
void* __dt__17soModelModuleImplFv(void*, short);
}

extern "C" void* fn_101_8F24(void* object, short deleting) {
    if (object != 0) {
        short memberDeleting = -1;
        __dt__17soModelModuleImplFv(static_cast<unsigned char*>(object) + 0x1F4, memberDeleting);
        fn_101_8F9C(static_cast<unsigned char*>(object) + 0x1AC, memberDeleting);
        fn_27_19A83C(object, memberDeleting);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
