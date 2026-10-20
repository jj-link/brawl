#pragma force_active on
extern "C" {
void* __dt__20soResourceModuleImplFv(void*, short);
void* fn_99_4144(void*, short);
}

extern "C" void* fn_99_5E88(void* object, short deleting) {
    if (object) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        __dt__20soResourceModuleImplFv(storage + 0xC, -1);
        if (object) {
            fn_99_4144(object, 0);
        }
        if (deleting > 0) operator delete(object);
    }
    return object;
}
