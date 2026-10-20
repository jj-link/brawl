#pragma force_active on
// fn_107_EDF4 destroys the Game & Watch embedded member whose storage begins
// at +0x204 of the passed object, then applies the outer object's own
// cleanup chain, mirroring a reverse-construction destructor: the embedded
// member's cleanup fn_107_ED94 runs with deleting flag -1 so the embedded
// storage is never freed independently, the outer memberless cleanup
// fn_107_EC60 runs with flag 0, and only a positive deleting flag releases
// the outer allocation itself via operator delete. The pointer is returned
// in every case.

void operator delete(void*);
extern "C" void* fn_107_ED94(void* object, short deleting);
extern "C" void* fn_107_EC60(void* object, short deleting);

extern "C" void* fn_107_EDF4(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_107_ED94(storage + 0x204, -1);
        if (object != 0) {
            fn_107_EC60(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
