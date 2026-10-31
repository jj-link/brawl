#pragma force_active on
typedef unsigned short u16;
typedef unsigned int u32;
typedef int s32;

extern "C" void fn_27_36354(void* p);

typedef struct {
    u16 a : 1;
    u16 b : 1;
    u16 c : 14;
} FlagWord;

extern "C" void fn_27_43504(unsigned char* self, u32 flag) {
    FlagWord* f = (FlagWord*)(self + 0x66);
    s32 bit;
    f->b = flag & 1;
    bit = f->b;
    if (bit == 1) {
        fn_27_36354(self + 0x38);
    }
}
