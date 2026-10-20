#pragma force_active on
void operator delete(void*);
extern "C" void fn_107_E934(void* object, short deleting);
extern "C" void* fn_107_EA6C(void* object, short deleting);

extern "C" void* fn_107_EACC(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_107_EA6C(storage + 0x17C, -1);
        if (object != 0) {
            fn_107_E934(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
