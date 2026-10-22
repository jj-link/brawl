#pragma force_active on
typedef unsigned int u32;

extern "C" {
void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
void* fn_800DAAEC(void*);
int fn_800305B0(int);
int fn_80030548(int);
}

extern "C" void* fn_800DAA30(u32 a, u32 b, u32 c, u32 d) {
    u32* obj = (u32*)__nw__FUlQ25Heaps8HeapType(0x70, 0x2A);
    if (obj != 0) {
        obj = (u32*)fn_800DAAEC(obj);
    }
    obj[0x40 / 4] = a;
    obj[0x44 / 4] = b;
    obj[0x4C / 4] = c;
    obj[0x58 / 4] = d;
    if (fn_800305B0(2) == 0) {
        obj[0x48 / 4] = 1;
        obj[0x50 / 4] = 4;
    } else {
        int t = fn_80030548(0x2B);
        obj[0x60 / 4] = t;
        if (t == 0) {
            obj[0x50 / 4] = 5;
        } else {
            obj[0x50 / 4] = 0;
        }
    }
    return obj;
}
