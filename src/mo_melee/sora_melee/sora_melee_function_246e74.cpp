#pragma force_active on
extern "C" void fn_27_2464C8(void*, int);
extern "C" unsigned char lbl_27_data_4EAA0[];

extern "C" void* fn_27_246E74(void* self, unsigned char arg) {
    fn_27_2464C8(self, 1);
    *(unsigned char*)((char*)self + 0x100) = arg;
    *(void**)((char*)self + 0x3C) = lbl_27_data_4EAA0;
    return self;
}
