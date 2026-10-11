extern "C" {
void* __dt__20soResourceModuleImplFv(void*, short);
void* fn_99_4144(void*, short);
}

// Destroy the resource module before the embedded base; only positive flags delete.
extern "C" void* fn_99_FFA0(void* object, short deleting) {
    if (object) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        int destroyMember = -1;
        __dt__20soResourceModuleImplFv(storage + 0x18, destroyMember);
        if (object) {
            int destroyBase = 0;
            fn_99_4144(object, destroyBase);
        }
        if (deleting > 0) operator delete(object);
    }
    return object;
}
