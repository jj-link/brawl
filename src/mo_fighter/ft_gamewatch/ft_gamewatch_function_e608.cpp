#pragma force_active on
void operator delete(void*);
extern "C" void* fn_107_E5A8(void* object, short deleting);
extern "C" void* fn_107_E478(void* object, short deleting);

extern "C" void* fn_107_E608(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_107_E5A8(storage + 0x94, -1);
        if (object != 0) {
            fn_107_E478(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
