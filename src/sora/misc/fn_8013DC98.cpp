#include <types.h>
#include <gf/gf_heap_manager.h>
#pragma force_active on
extern "C" {
void __dl__FPv(void*);
void __destroy_arr(void*, void (*)(void*, s16), u32, u32);
void __dt__8NtBufferFv(void*, s16);
extern unsigned char lbl_8045E7AC[];
extern unsigned char __vt__8NtBuffer[];
extern s32 lbl_805A0390;
}
class NtBuffer {
public:
    virtual void slot0();
    virtual void allocBuffer(unsigned long, int);
    virtual void freeBuffer();
};
struct Obj {
    char pad0[0x38];
    NtBuffer b38;
    char pad1[0x114];
    NtBuffer b150;
    char pad2[0x14];
    NtBuffer b168;
    char pad3[0xc0];
    NtBuffer buf;
    s32 a, b;
    unsigned char flag;
    char pad[3];
    void* data;
    s32 c,d,e,f;
};
extern "C" void* fn_8013DC98(Obj* arg0, s32 arg1) {
    if (arg0 != 0) {
        lbl_805A0390 = 0;
        if ((s32)arg0 + 0x22C) {
            *(void**)&arg0->buf = lbl_8045E7AC;
            if (arg0->flag == 0) {
                if (arg0->data != 0) {
                    gfHeapManager::free(arg0->data);
                }
            }
            arg0->data = 0;
            arg0->a = 0;
            arg0->b = 0;
            arg0->c = 0;
            arg0->d = 0;
            arg0->e = 0;
            arg0->f = 0;
            if ((char*)arg0 + 0x22C) {
                *(void**)&arg0->buf = __vt__8NtBuffer;
                arg0->buf.freeBuffer();
            }
        }
        if ((s32)arg0 + 0x168) {
            if ((s32)arg0 + 0x168) {
                *(void**)&arg0->b168 = __vt__8NtBuffer;
                arg0->b168.freeBuffer();
            }
        }
        if ((char*)arg0 + 0x150) {
            *(void**)&arg0->b150 = __vt__8NtBuffer;
            arg0->b150.freeBuffer();
        }
        __destroy_arr((char*)arg0 + 0x58, __dt__8NtBufferFv, 0x14, 4);
        if ((char*)arg0 + 0x38) {
            *(void**)&arg0->b38 = __vt__8NtBuffer;
            arg0->b38.freeBuffer();
        }
        if (arg1 > 0) {
            __dl__FPv(arg0);
        }
    }
    return arg0;
}