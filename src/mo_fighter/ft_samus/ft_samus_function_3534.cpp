#pragma force_active on
void operator delete(void*);

extern "C" void* fn_94_33FC(void*, short);

extern "C" void* fn_94_3534(void* object, short deleting) {
    if (object != 0) {
        unsigned char* member = static_cast<unsigned char*>(object) + 8;
        fn_94_33FC(member, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
