#pragma force_active on
extern "C" void fn_27_4B53C(void*, short);
extern "C" void fn_27_19C45C(void*, short);

extern "C" void* fn_108_75E8(void* self, short param) {
    if (self != 0) {
        unsigned char* storage = static_cast<unsigned char*>(self);
        fn_27_4B53C(storage + 0x17c, -1);
        fn_27_19C45C(self, -1);
        if (param > 0) {
            operator delete(self);
        }
    }
    return self;
}
