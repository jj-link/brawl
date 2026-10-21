#pragma force_active on
extern "C" void* fn_801C2C04(void* self);
extern "C" void* fn_801C2C9C(void* base, int index);
extern "C" int fn_801C2458(const unsigned char* ptr);

extern "C" int fn_80077D54(unsigned char* self, int arg) {
    if (self[0x6EF] == 0) {
        return 0;
    }
    return fn_801C2458((const unsigned char*)fn_801C2C9C(fn_801C2C04(self), arg));
}
