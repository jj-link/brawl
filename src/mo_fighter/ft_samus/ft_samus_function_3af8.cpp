#pragma force_active on
void operator delete(void*);
extern "C" void* fn_94_3B70(void* object, short deleting);
extern "C" void fn_94_3D74(void* object, short deleting);

extern "C" void* fn_94_3AF8(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_94_3B70(storage + 0x6238, -1);
        if (object != 0) {
            fn_94_3D74(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
