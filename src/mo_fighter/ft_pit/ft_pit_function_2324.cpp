#pragma force_active on
void operator delete(void*);
extern "C" void* fn_112_2390(void*, short);
extern "C" void* fn_112_21EC(void*, short);

extern "C" void* fn_112_2324(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_112_2390(storage + 0x50, -1);
        fn_112_21EC(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
