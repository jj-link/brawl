#pragma force_active on
void operator delete(void*);
extern "C" void fn_95_6B1C(void* object, short deleting);
extern "C" void* fn_27_1A1E70(void* object, short deleting);

extern "C" void* fn_95_6AA4(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_27_1A1E70(storage + 0x190, -1);
        if (object != 0) {
            fn_95_6B1C(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
