#pragma force_active on
void operator delete(void*);
extern "C" void* fn_27_97968(void*, short);

extern "C" void* fn_27_36A0A4(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_27_97968(storage + 0x14, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}