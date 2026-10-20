#pragma force_active on
void operator delete(void*);
extern "C" void* fn_94_3DEC(void* object, short deleting);
extern "C" void* fn_94_3EAC(void* object, short deleting);

extern "C" void* fn_94_3D74(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_94_3DEC(storage + 0x49F8, -1);
        if (object != 0) {
            fn_94_3EAC(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
