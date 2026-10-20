#pragma force_active on
void operator delete(void*);
extern "C" void* fn_122_129C0(void* object, short deleting);
extern "C" void* fn_122_128E8(void* object, short deleting);

extern "C" void* fn_122_12A20(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_122_129C0(storage + 0x1C8, -1);
        if (object != 0) {
            fn_122_128E8(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
