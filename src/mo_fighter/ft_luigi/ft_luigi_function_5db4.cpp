#pragma force_active on
extern "C" {
void* fn_99_5E2C(void*, short);
void* __dt__17soModelModuleImplFv(void*, short);
void fn_27_CBC74(void*, short);
}

// Destroy the embedded modules owned by this layer, then optionally the layer itself.
extern "C" void* fn_99_5DB4(void* object, short deleting) {
    if (object) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        int destroyMember = -1;
        __dt__17soModelModuleImplFv(storage + 0x290, destroyMember);
        fn_99_5E2C(storage + 0x248, destroyMember);
        fn_27_CBC74(object, destroyMember);
        if (deleting > 0) operator delete(object);
    }
    return object;
}
