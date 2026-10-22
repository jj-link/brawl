#include <types.h>
#pragma force_active on

extern char lbl_80454530[];
extern int g_sndSystem;
extern float lbl_805A1B08;

extern "C" {
void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
void* fn_801C5D08(void* p, int a, int b);
void fn_801C6050(void* self, float* src);
}

class snd3DGenerator {
public:
    snd3DGenerator();
    void* m0;
    char* m4;
};

snd3DGenerator::snd3DGenerator() {
    m4 = lbl_80454530;
    int sys = g_sndSystem;
    void* p = __nw__FUlQ25Heaps8HeapType(0xc4, 5);
    if (p != 0) {
        p = fn_801C5D08(p, sys + 0x18c, sys + 0x26c);
    }
    m0 = p;
    float v[3];
    v[0] = lbl_805A1B08;
    v[1] = lbl_805A1B08;
    v[2] = lbl_805A1B08;
    fn_801C6050(m0, v);
}
