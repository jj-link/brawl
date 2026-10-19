#pragma force_active on
void operator delete(void*);
extern "C" void fn_94_14E8C(void*, short);
extern "C" void* fn_94_15608(void*, short);

extern "C" void* fn_94_14E20(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_94_14E8C(storage + 0x17FC, -1);
        fn_94_15608(storage + 0x4, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
