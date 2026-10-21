#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;

struct Element {
    u32 low : 3;
    u32 bit3 : 1;
    u32 high : 28;
    u8 padding[0x44];
};

struct Outer {
    u32 x0;
    u32 x4;
    u32 x8;
    struct Element* array;
};

extern "C" void fn_800B93DC(struct Outer* outer, int index, int flag) {
    outer->array[index].bit3 = flag;
}