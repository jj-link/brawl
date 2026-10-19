#pragma force_active on
void operator delete(void*);
extern "C" void fn_94_3390(void* object, short deleting);
extern "C" void fn_94_3594(void* object, short deleting);

extern "C" void* fn_94_3314(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_94_3390(storage + 0x175E8, -1);
        if (object != 0) {
            fn_94_3594(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
