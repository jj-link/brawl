#pragma force_active on
extern "C" void fn_27_22A38(void*, short);
extern "C" void fn_27_1A2910(void*, short);
void operator delete(void*);

// Release the embedded member before the base, retaining their storage.
extern "C" void* fn_109_61F0(void* object, short deleting) {
    if (object != 0) {
        char* storage = static_cast<char*>(object);
        fn_27_22A38(storage + 0x34, -1);
        fn_27_1A2910(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
