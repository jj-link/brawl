#pragma force_active on
void operator delete(void*);
extern "C" void* fn_27_97968(void*, short);
extern "C" void* fn_27_1CCCC(void*, short);

extern "C" void* fn_116_3A60(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_27_97968(storage + 0x14, -1);
        fn_27_1CCCC(storage + 0x4, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
