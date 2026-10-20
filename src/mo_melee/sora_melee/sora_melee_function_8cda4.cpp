#pragma force_active on
extern "C" int fn_27_8CDA4(void* self) {
    unsigned char* p = (unsigned char*)self;
    p = *(unsigned char**)(p + 0x60);
    p = *(unsigned char**)(p + 0xd8);
    return *(int*)(p + 0x3c);
}
