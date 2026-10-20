#pragma force_active on
void operator delete(void*);
extern "C" {
void* __dt__17soModelModuleImplFv(void*, short);
void* fn_111_5BEC(void*, short);
void* fn_27_19A83C(void*, short);
}

extern "C" void* fn_111_5B74(void* object, short deleting) {
    if (object != 0) {
        char* storage = static_cast<char*>(object);
        short destroy = -1;
        __dt__17soModelModuleImplFv(storage + 0x1f4, destroy);
        fn_111_5BEC(storage + 0x1ac, destroy);
        fn_27_19A83C(object, destroy);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
