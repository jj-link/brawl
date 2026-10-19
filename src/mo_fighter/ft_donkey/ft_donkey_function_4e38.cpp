#pragma force_active on
void operator delete(void*);
extern "C" void* fn_92_4914(void*, short);
extern "C" void* fn_92_4EA4(void*, short);

extern "C" void* fn_92_4E38(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_92_4914(storage + 0x1FDC, -1);
        fn_92_4EA4(storage + 0x4, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
