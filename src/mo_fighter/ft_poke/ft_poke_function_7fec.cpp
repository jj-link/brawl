#pragma force_active on
extern "C" {
void fn_27_1999C4(void* ptr, int a, int b);
void fn_27_19BF3C(void* ptr, int a, int b);
void fn_27_150320(void* ptr, void* a, short b, void* c, void* d);
}

struct Block { char _; };

extern "C" void* fn_116_7FEC(Block* object, void* arg2, short arg3) {
    fn_27_1999C4(object, 0xA, 0);
    fn_27_19BF3C(object + 0x584, 2, 0);
    fn_27_150320(object + 0x5B8, arg2, arg3, object, object + 0x584);
    return object;
}
