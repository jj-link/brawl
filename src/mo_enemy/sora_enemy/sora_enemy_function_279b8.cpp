#pragma force_active on
typedef unsigned char u8;

extern "C" void fn_27_6A244(void*);
extern "C" void setIdentity__6MatrixFv(void*);
extern "C" u8 lbl_41_data_34C8[];

extern "C" void* fn_41_279B8(void* self) {
    u8* s = (u8*)self;
    fn_27_6A244(self);
    u8* p = lbl_41_data_34C8;
    *(u8**)(s + 0x0) = p;
    *(u8**)(s + 0x8) = p + 0x1c8;
    setIdentity__6MatrixFv(s + 0x54);
    return self;
}
