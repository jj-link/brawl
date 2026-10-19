#pragma force_active on
void operator delete(void*);
extern "C" void fn_27_1A20EC(void*, short);
extern "C" void* fn_118_3CA8(void*, short);

extern "C" void* fn_118_4F70(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_27_1A20EC(storage + 0x10, -1);
        fn_118_3CA8(object, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
