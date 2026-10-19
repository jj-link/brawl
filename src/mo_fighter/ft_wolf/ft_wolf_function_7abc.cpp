#pragma force_active on
void operator delete(void*);
extern "C" void fn_27_22A38(void*, short);
extern "C" void fn_27_1A2910(void*, short);

extern "C" void* fn_125_7ABC(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_27_22A38(storage + 0x34, -1);
        fn_27_1A2910(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
