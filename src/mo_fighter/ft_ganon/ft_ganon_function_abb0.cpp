#pragma force_active on
void operator delete(void*);
extern "C" void* fn_109_AB50(void* object, short deleting);
extern "C" void* fn_109_AA1C(void* object, short deleting);

extern "C" void* fn_109_ABB0(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_109_AB50(storage + 0x134, -1);
        if (object != 0) {
            fn_109_AA1C(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
