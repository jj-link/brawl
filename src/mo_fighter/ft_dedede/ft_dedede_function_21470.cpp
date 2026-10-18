#pragma force_active on
void operator delete(void*);
extern "C" void* fn_117_21410(void*, short);

extern "C" void* fn_117_21470(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_117_21410(storage + 8, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
