#pragma force_active on
void operator delete(void*);
extern "C" {
void* __dt__17soModelModuleImplFv(void*, short);
void* fn_27_CBDE8(void*, short);
}

extern "C" void* fn_100_4564(void* object, short deleting) {
    if (object != 0) {
        short destroy = -1;
        __dt__17soModelModuleImplFv(static_cast<char*>(object) + 0x114, destroy);
        fn_27_CBDE8(object, destroy);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
