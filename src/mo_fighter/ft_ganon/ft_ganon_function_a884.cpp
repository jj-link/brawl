#pragma force_active on
void operator delete(void*);
extern "C" void fn_109_A824(void* object, short deleting);
extern "C" void fn_109_A6F4(void* object, short deleting);

extern "C" void* fn_109_A884(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_109_A824(storage + 0x94, -1);
        if (object != 0) {
            fn_109_A6F4(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
