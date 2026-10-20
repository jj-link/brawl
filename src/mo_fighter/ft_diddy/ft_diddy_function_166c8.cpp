#pragma force_active on
void operator delete(void*);
extern "C" void* fn_115_1665C(void*, short);
extern "C" void* fn_115_165D0(void*, short);
extern "C" void* fn_115_16544(void*, short);
extern "C" void* fn_115_164B8(void*, short);
extern "C" void* fn_115_1642C(void*, short);

extern "C" void* fn_115_166C8(void* object, short deleting) {
    if (object != 0) {
        short minus = -1;
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_115_1665C(storage + 0x4B0, minus);
        fn_115_165D0(storage + 0x384, minus);
        fn_115_16544(storage + 0x258, minus);
        fn_115_164B8(storage + 0x12C, minus);
        fn_115_1642C(object, minus);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
