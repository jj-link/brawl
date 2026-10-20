#pragma force_active on
extern "C" void* fn_95_4054(void* object, short deleting);
extern "C" void* fn_95_7B88(void* self, short deleting);
extern "C" void* fn_27_CD934(void* object, short deleting);
extern void operator delete(void*);

extern "C" void* fn_95_7B10(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_95_4054(storage + 0xAC, -1);
        fn_95_7B88(storage + 0x20, -1);
        fn_27_CD934(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
