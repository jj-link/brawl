#pragma force_active on
extern "C" void fn_110_5D68(void*, short);
extern "C" void fn_110_41F4(void*, short);
void operator delete(void*);

// Release the embedded member at +0x24 before the base, deleting only if requested.
extern "C" void* fn_110_5CFC(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_110_5D68(storage + 0x24, -1);
        fn_110_41F4(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
