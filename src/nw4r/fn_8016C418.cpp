#pragma force_active on
extern "C" {
    void fn_8015BF9C(void*, int);
    extern int lbl_804653A0[];
}

extern "C" void* fn_8016C418(void* self) {
    char* p = (char*)self;
    *(int*)(p + 0x1C) = (int)&lbl_804653A0;
    fn_8015BF9C(p + 0x38, 0x14);
    fn_8015BF9C(p + 0x44, 0x14);
    *(short*)(p + 0x50) = 0;
    return self;
}
