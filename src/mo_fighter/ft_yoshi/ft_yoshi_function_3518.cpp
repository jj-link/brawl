#pragma force_active on
void operator delete(void*);
extern "C" void* fn_95_3584(void*, short);
extern "C" void* fn_95_4B40(void*, short);

extern "C" void* fn_95_3518(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_95_3584(storage + 0x1fec, -1);
        fn_95_4B40(storage + 0x4, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
