#pragma force_active on
void operator delete(void*);
extern "C" void fn_109_A9BC(void* object, short deleting);
extern "C" void fn_109_A884(void* object, short deleting);

extern "C" void* fn_109_AA1C(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_109_A9BC(storage + 0xEC, -1);
        if (object != 0) {
            fn_109_A884(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
