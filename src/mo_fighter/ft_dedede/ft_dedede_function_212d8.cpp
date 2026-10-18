#pragma force_active on
void operator delete(void*);
extern "C" void* fn_117_20F6C(void*, short);

extern "C" void* fn_117_212D8(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_117_20F6C(storage + 4, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
