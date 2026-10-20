#pragma force_active on
void operator delete(void*);
extern "C" void* fn_122_5F84(void* object, short deleting);
extern "C" void* fn_122_656C(void* object, short deleting);

extern "C" void* fn_122_5F08(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_122_5F84(storage + 0x16A8C, -1);
        if (object != 0) {
            fn_122_656C(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
