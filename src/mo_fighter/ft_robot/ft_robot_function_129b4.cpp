#pragma force_active on
void operator delete(void*);
extern "C" void* fn_120_12954(void*, short);
extern "C" void* fn_120_49C4(void*, short);

// Release the sub-object at +0x24, run the base teardown, then free storage if deleting.
extern "C" void* fn_120_129B4(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_120_12954(storage + 0x24, -1);
        fn_120_49C4(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
