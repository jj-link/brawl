#pragma force_active on
extern "C" {
    extern char g_Network[];
    int fn_27_255068();
    void fn_8013F0B0(void* p);
}

extern "C" int fn_27_254FE8(unsigned char* self) {
    int ret;
    if (self[0x49] != 0) {
        if (fn_27_255068()) {
            fn_8013F0B0(*(void**)(g_Network + 0x34));
            ret = 1;
        } else {
            unsigned char* n = *(unsigned char**)(g_Network + 0x34);
            ret = 0;
            if (*(int*)(n + 0xA8) == 6 && *(int*)(n + 0x1E0) == 0) {
                ret = 1;
            }
        }
    } else {
        ret = 1;
    }
    return ret;
}
