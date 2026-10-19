#pragma force_active on
void operator delete(void*);
extern "C" void* fn_112_4134(void*, short);
extern "C" void* fn_112_4DD4(void*, short);

extern "C" void* fn_112_4D68(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_112_4134(storage + 0x3FC8, -1);
        fn_112_4DD4(storage + 0x4, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
