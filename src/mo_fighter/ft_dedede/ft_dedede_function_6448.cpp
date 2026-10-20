#pragma force_active on
void operator delete(void*);

extern "C" {
void* __dt__20soResourceModuleImplFv(void*, short);
void fn_117_64C0(void*, short);
}

extern "C" void* fn_117_6448(void* object, short deleting) {
    if (object != 0) {
        __dt__20soResourceModuleImplFv(static_cast<unsigned char*>(object) + 0x0C, -1);
        if (object != 0) {
            fn_117_64C0(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
