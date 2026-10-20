#pragma force_active on
void operator delete(void*);
extern "C" void* fn_122_1255C(void* object, short deleting);
extern "C" void* fn_122_12424(void* object, short deleting);

extern "C" void* fn_122_125BC(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_122_1255C(storage + 0xEC, -1);
        if (object != 0) {
            fn_122_12424(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
