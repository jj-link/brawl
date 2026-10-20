#pragma force_active on
extern "C" void* __dt__20soResourceModuleImplFv(void*, short);
extern "C" void fn_123_470C(void* p, short n);
void operator delete(void*);

extern "C" void* fn_123_4694(void* object, short deleting) {
    unsigned char* storage = static_cast<unsigned char*>(object);
    if (object != 0) {
        __dt__20soResourceModuleImplFv(storage + 0x18, -1);
        if (object != 0) {
            fn_123_470C(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
