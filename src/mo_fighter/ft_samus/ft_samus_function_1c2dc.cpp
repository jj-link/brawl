#pragma force_active on
void operator delete(void*);
extern "C" void* fn_94_1C34C(void*, short);
extern "C" void* fn_94_1C60C(void*, short);

extern "C" void* fn_94_1C2DC(void* object, short deleting) {
    if (object != 0) {
        fn_94_1C34C(static_cast<unsigned char*>(object) + 0x18f0, -1);
        fn_94_1C60C(object, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
