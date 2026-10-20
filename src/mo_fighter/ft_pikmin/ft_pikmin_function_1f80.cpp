#pragma force_active on
// fn_113_1F80 destroys the Pikmin embedded member whose storage begins at
// +0x4384 of the passed object and then applies the outer object's own
// cleanup. The embedded member's own cleanup fn_113_1FF8 is called with -1
// so the embedded storage is never freed independently. The outer object's
// memberless cleanup fn_113_38AC runs with flag 0, and only a positive
// deleting flag releases the outer allocation itself. The pointer is
// returned in every case.
void operator delete(void*);
extern "C" void* fn_113_1FF8(void* object, short deleting);
extern "C" void* fn_113_38AC(void* object, short deleting);

extern "C" void* fn_113_1F80(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_113_1FF8(storage + 0x4384, -1);
        if (object != 0) {
            fn_113_38AC(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
