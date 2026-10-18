#pragma force_active on
void operator delete(void*);
extern "C" void fn_121_486C(void*, short);

extern "C" void* fn_121_4978(void* object, short deleting) {
    if (object != 0) {
        unsigned char* member = static_cast<unsigned char*>(object) + 0x88;
        fn_121_486C(member, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
