#pragma force_active on
void operator delete(void*);
extern "C" void* fn_93_D328(void* object, short deleting);
extern "C" void fn_93_D1F0(void* object, short deleting);

extern "C" void* fn_93_D388(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_93_D328(storage + 0xEC, -1);
        if (object != 0) {
            fn_93_D1F0(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
