#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;

extern "C" {
void fn_27_711E4(void* a, short b, void* c);
void* fn_27_1AB96C(void* o, u8 c);
void* fn_104_8710(void* self, short arg);
}

extern "C" void* fn_104_8710(void* self, short arg) {
    fn_27_711E4(self, arg, (char*)self + 0x24);
    fn_27_1AB96C((void*)((u32)self + 0x24), 0);
    return self;
}
