#pragma force_active on
void operator delete(void*);
extern "C" void* fn_95_5938(void*, short);
extern "C" void* fn_95_5C48(void*, short);

extern "C" void* fn_95_5BDC(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_95_5938(storage + 0x1F40, -1);
        fn_95_5C48(storage + 0x4, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
