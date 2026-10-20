#pragma force_active on
void operator delete(void*);
extern "C" void* fn_122_7E70(void* object, short deleting);
extern "C" void* fn_122_814C(void* object, short deleting);

extern "C" void* fn_122_7DF8(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_122_7E70(storage + 0x6CA8, -1);
        if (object != 0) {
            fn_122_814C(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
