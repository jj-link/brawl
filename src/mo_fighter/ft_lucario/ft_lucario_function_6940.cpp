#pragma force_active on
void operator delete(void*);
extern "C" void* __dt__17soModelModuleImplFv(void*, short);
extern "C" void* fn_118_69B8(void*, short);
extern "C" void* fn_27_19A83C(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_118_6940(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        __dt__17soModelModuleImplFv(storage + 0x1f4, -1);
        fn_118_69B8(storage + 0x1ac, -1);
        fn_27_19A83C(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
