#pragma force_active on
void operator delete(void*);
extern "C" {
void* __dt__17soModelModuleImplFv(void*, short);
void* fn_100_6914(void*, short);
void* fn_27_19A83C(void*, short);
}

extern "C" void* fn_100_689C(void* object, short deleting) {
    if (object != 0) {
        char* storage = static_cast<char*>(object);
        short destroy = -1;
        __dt__17soModelModuleImplFv(storage + 0x1f4, destroy);
        fn_100_6914(storage + 0x1ac, destroy);
        fn_27_19A83C(object, destroy);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
