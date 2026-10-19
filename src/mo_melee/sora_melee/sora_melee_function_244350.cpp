#pragma force_active on
extern "C" void fn_27_242764(void* self);
extern "C" unsigned char lbl_27_data_4E408[];

extern "C" void* fn_27_244350(void* self) {
    unsigned char* p = (unsigned char*)self;
    fn_27_242764(self);
    p[0x1B5] = 0;
    *(void**)(p + 0x3C) = lbl_27_data_4E408;
    p[0x40] = 0;
    *(int*)(p + 0x1B8) = 0;
    return self;
}
