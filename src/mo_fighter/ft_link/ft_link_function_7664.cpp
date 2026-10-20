#pragma force_active on
void operator delete(void*);
extern "C" void* fn_93_7604(void* object, short deleting);
extern "C" void* fn_93_752C(void* object, short deleting);

extern "C" void* fn_93_7664(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_93_7604(storage + 0x6600, -1);
        if (object != 0) {
            fn_93_752C(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
