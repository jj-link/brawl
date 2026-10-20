#pragma force_active on
extern "C" {
void __dt__24soCollisionHitModuleImplFv(void*, short);
void fn_27_CC984(void*, short);
void fn_27_4CAA0(void*, short);
void fn_27_19B704(void*, short);
}

void operator delete(void*);

extern "C" void* fn_119_4D68(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        __dt__24soCollisionHitModuleImplFv(storage + 0x8F4, -1);
        fn_27_CC984(storage + 0x8B0, -1);
        fn_27_4CAA0(storage + 0x82C, -1);
        fn_27_19B704(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
