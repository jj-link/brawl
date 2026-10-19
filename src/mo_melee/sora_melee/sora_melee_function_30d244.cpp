#pragma force_active on
typedef unsigned char u8;
extern "C" void fn_27_5B248(void* self, int a, int b, int c);

extern "C" void* fn_27_30D244(void* self, int a, int b) {
    fn_27_5B248(self, a, b, 1);
    return self;
}
