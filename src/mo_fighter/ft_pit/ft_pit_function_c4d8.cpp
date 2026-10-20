#pragma force_active on
void operator delete(void*);
extern "C" void* fn_112_C478(void* object, short deleting);
extern "C" void fn_112_C340(void* object, short deleting);

extern "C" void* fn_112_C4D8(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_112_C478(storage + 0xEC, -1);
        if (object != 0) {
            fn_112_C340(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
