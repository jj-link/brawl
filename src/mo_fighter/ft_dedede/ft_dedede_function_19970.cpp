void operator delete(void*);

extern "C" {
void* __dt__20soResourceModuleImplFv(void*, short);
void fn_117_64C0(void*, short);
}

// Destroy the resource module member, then the base object; only the outer
// deleting flag releases the allocation.
extern "C" void* fn_117_19970(void* object, short deleting) {
    if (object != 0) {
        __dt__20soResourceModuleImplFv(static_cast<unsigned char*>(object) + 0x18, -1);
        if (object != 0) {
            fn_117_64C0(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
