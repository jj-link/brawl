#pragma force_active on
typedef unsigned int u32;

struct Word8 {
    u32 hi : 10;
    u32 field : 5;
    u32 lo : 17;
};

extern "C" void fn_27_19A18C(void* obj, u32 value) {
    Word8* w = (Word8*)((char*)obj + 8);
    w->field = value;
}
