#pragma force_active on
extern "C" {
void* fn_27_B5324(void*, short);
void* fn_104_70EC(void*, short);
void* fn_104_714C(void*, short);
}

extern "C" void* fn_104_7074(void* object, short deleting) {
    if (object) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        short destroy = -1;
        fn_27_B5324(storage + 0x30, destroy);
        fn_104_70EC(storage + 0x18, destroy);
        fn_104_714C(storage + 0x4, destroy);
        if (deleting > 0) operator delete(object);
    }
    return object;
}
