#pragma force_active on
void operator delete(void*);
extern "C" void* fn_94_3BDC(void*, short);
extern "C" void* fn_94_3D14(void*, short);

extern "C" void* fn_94_3CA8(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_94_3BDC(storage + 0x17D8, -1);
        fn_94_3D14(storage + 0x4, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
