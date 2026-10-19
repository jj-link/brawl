#pragma force_active on
void operator delete(void*);
extern "C" void fn_95_3518(void* object, short deleting);
extern "C" void fn_95_4BA0(void* object, short deleting);

extern "C" void* fn_95_349C(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_95_3518(storage + 0x15DCC, -1);
        if (object != 0) {
            fn_95_4BA0(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
