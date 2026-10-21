#pragma force_active on
extern "C" int fn_8006A470(void* self) {
    signed char* p = (signed char*)self;
    p[0] = 0x12;
    p[1] = -0x80;
    return 2;
}
