#pragma force_active on
void operator delete(void*);
extern "C" void fn_97_477C(void* object, short deleting);
extern "C" void* fn_97_3448(void* object, short deleting);

extern "C" void* fn_97_33CC(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_97_3448(storage + 0x12E84, -1);
        if (object != 0) {
            fn_97_477C(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
