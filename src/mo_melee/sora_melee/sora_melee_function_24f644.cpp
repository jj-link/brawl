#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;

extern "C" void fn_27_247D98(void*);

extern "C" u8 lbl_27_data_4F680[];

extern "C" void* fn_27_24F644(void* self) {
    fn_27_247D98(self);
    *(u8*)((char*)self + 0x40) = 0;
    *(u32*)((char*)self + 0x3C) = (u32)lbl_27_data_4F680;
    return self;
}
