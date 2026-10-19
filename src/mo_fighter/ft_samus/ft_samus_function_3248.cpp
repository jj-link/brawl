#pragma force_active on
void operator delete(void*);
extern "C" void* fn_94_32B8(void*, short);
extern "C" void* fn_94_4DBC(void*, short);

extern "C" void* fn_94_3248(void* object, short deleting) {
    if (object != 0) {
        fn_94_32B8(static_cast<unsigned char*>(object) + 0x8, -1);
        fn_94_4DBC(object, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
