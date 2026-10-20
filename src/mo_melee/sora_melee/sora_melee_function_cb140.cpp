#pragma force_active on
typedef unsigned int u32;

struct Word8 {
    u32 hi : 10;
    u32 f : 5;
    u32 lo : 17;
};

extern "C" void fn_27_CB140(unsigned char* obj, u32 v) {
    Word8* w = (Word8*)(obj + 8);
    w->f = v;
}
