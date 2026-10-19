#pragma force_active on
typedef signed char s8;
typedef short s16;
typedef unsigned char u8;

extern "C" void fn_27_D3B18(void* p, s16 x);
extern "C" void fn_27_D3B38(void* self, s16 a, s8 b);
extern "C" u8 lbl_41_data_5F50[];

extern "C" void* fn_41_2D890(void* self, s16 a, s8 b) {
    fn_27_D3B18(self, 6);
    *(void**)self = lbl_41_data_5F50;
    fn_27_D3B38(self, a, b);
    return self;
}
