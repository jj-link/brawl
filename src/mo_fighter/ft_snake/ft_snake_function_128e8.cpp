#pragma force_active on
void operator delete(void*);
extern "C" void* fn_122_12888(void* object, short deleting);
extern "C" void fn_122_12750(void* object, short deleting);

extern "C" void* fn_122_128E8(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_122_12888(storage + 0x17C, -1);
        if (object != 0) {
            fn_122_12750(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
