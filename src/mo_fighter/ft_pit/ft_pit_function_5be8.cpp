#pragma force_active on
void operator delete(void*);
extern "C" void* fn_112_3CC8(void*, short);
extern "C" void* fn_112_5C60(void*, short);
extern "C" void* fn_27_19E99C(void*, short);

extern "C" void* fn_112_5BE8(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_112_3CC8(storage + 0x85C, -1);
        fn_112_5C60(storage + 0x19C, -1);
        fn_27_19E99C(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
