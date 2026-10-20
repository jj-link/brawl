#pragma force_active on
// fn_110_AF64 destroys the Wario embedded member whose storage begins at
// +0x94 of the passed object and then applies the outer object's own
// cleanup chain. The embedded member's own cleanup fn_110_AF04 is called
// here with -1 so the embedded storage is never freed independently. The
// outer object's cleanup fn_110_ADD4 runs with flag 0, and only a positive
// deleting flag releases the outer allocation itself. The pointer is
// returned in every case.
void operator delete(void*);
extern "C" void fn_110_AF04(void* object, short deleting);
extern "C" void* fn_110_ADD4(void* object, short deleting);

extern "C" void* fn_110_AF64(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_110_AF04(storage + 0x94, -1);
        if (object != 0) {
            fn_110_ADD4(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
