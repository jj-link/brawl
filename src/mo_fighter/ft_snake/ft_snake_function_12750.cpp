#pragma force_active on
void operator delete(void*);
extern "C" void fn_122_126F0(void* object, short deleting);
extern "C" void fn_122_125BC(void* object, short deleting);

extern "C" void* fn_122_12750(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_122_126F0(storage + 0x134, -1);
        if (object != 0) {
            fn_122_125BC(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
