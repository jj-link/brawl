#pragma force_active on
void operator delete(void*);
extern "C" void* fn_94_3BDC(void*, short);
extern "C" void* fn_94_3C3C(void*, short);

extern "C" void* fn_94_3B70(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_94_3BDC(storage + 0x4778, -1);
        fn_94_3C3C(storage + 0x4, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
