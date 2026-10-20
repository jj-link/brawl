#pragma force_active on
void operator delete(void*);
extern "C" void fn_126_7ECC(void* object, short deleting);
extern "C" void* fn_126_7D9C(void* object, short deleting);

extern "C" void* fn_126_7F2C(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_126_7ECC(storage + 0x94, -1);
        if (object != 0) {
            fn_126_7D9C(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
