#pragma force_active on
void operator delete(void*);

extern "C" void* fn_112_F098(void* object, short deleting);
extern "C" void* fn_112_EF5C(void* object, short deleting);
extern "C" void* fn_112_E728(void* object, short deleting);

extern "C" void* fn_112_11044(void* object, short deleting) {
    if (object != 0) {
        short notDeleting = -1;
        fn_112_F098(static_cast<unsigned char*>(object) + 0x22d8, notDeleting);
        short baseDeleting = 0;
        fn_112_EF5C(static_cast<unsigned char*>(object) + 0x22c8, baseDeleting);
        fn_112_E728(object, baseDeleting);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
