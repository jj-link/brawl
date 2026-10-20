#pragma force_active on
void operator delete(void*);
extern "C" void* fn_117_21F0(void*, short);
extern "C" void* fn_117_228C(void*, short);
extern "C" void* fn_117_22CC(void*, short);
extern "C" void* fn_27_C7770(void*, short);

// Destroy embedded members before the base, releasing only a deleting object.
extern "C" void* fn_117_26AC(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_117_21F0(storage + 0xdc, -1);
        fn_117_228C(storage + 0xc0, -1);
        fn_117_22CC(storage + 0x14, -1);
        if (object != 0) {
            fn_27_C7770(object, -1);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
