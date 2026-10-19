#pragma force_active on
extern "C" void* fn_8008F230(void* p);

extern "C" void* fn_27_11DF0(void* self) {
    char* p = (char*)self;
    void* r0 = *(void**)(p + 0x28);
    if (r0 != 0) {
        return fn_8008F230(r0);
    }
    char* r3 = *(char**)(p + 0x2c);
    if (r3 != 0) {
        if (*(unsigned char*)(r3 + 8) != 0) {
            return fn_8008F230(*(void**)(r3 + 4));
        }
        return fn_8008F230(*(void**)(r3 + 0));
    }
    return 0;
}
