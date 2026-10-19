#pragma force_active on
void operator delete(void*);
extern "C" void* fn_108_4864(void*, short);
extern "C" void* fn_108_5010(void*, short);

extern "C" void* fn_108_4FA4(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_108_4864(storage + 0x647C, -1);
        fn_108_5010(storage + 0x4, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
