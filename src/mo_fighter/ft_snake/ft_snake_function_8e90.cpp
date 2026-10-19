#pragma force_active on
void operator delete(void*);
extern "C" void* fn_122_1F14(void* p, short flag);
extern "C" void* fn_122_4040(void* object, short deleting);

extern "C" void* fn_122_8E90(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_122_1F14(storage + 0x20, 0);
        fn_122_4040(object, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
