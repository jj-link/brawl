#pragma force_active on
void operator delete(void*);
extern "C" void fn_109_10188(void*, short);
extern "C" void fn_109_10428(void*, short);

extern "C" void* fn_109_10118(void* object, short deleting) {
    if (object != 0) {
        fn_109_10188(static_cast<unsigned char*>(object) + 0x274c, -1);
        fn_109_10428(object, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
