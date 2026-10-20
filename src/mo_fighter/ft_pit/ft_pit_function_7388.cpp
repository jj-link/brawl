#pragma force_active on
void operator delete(void*);
extern "C" void* fn_112_7400(void* object, short deleting);
extern "C" void* fn_27_19A83C(void* object, short deleting);
extern "C" void __dt__17soModelModuleImplFv(void* object, short deleting);

extern "C" void* fn_112_7388(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        __dt__17soModelModuleImplFv(storage + 0x1F4, -1);
        fn_112_7400(storage + 0x1AC, -1);
        fn_27_19A83C(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
