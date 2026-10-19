#pragma force_active on
void operator delete(void*);
extern "C" void* fn_94_140C8(void* p, short flag);
extern "C" void* fn_94_4DBC(void* p, short flag);

extern "C" void* fn_94_14058(void* object, short deleting) {
    if (object != 0) {
        fn_94_140C8(static_cast<unsigned char*>(object) + 0x8, -1);
        fn_94_4DBC(object, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
