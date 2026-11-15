#include <types.h>
#pragma force_active on

struct NameTable { const char* names[15]; };
struct State { u8 padding[0xFCB]; u8 initialized : 1; u8 otherFlags : 7; };

extern "C" {
int fn_800CC070(u8*, int*);
int fn_800CC2C0(void*);
void flushLogToSDCard__Fv();
void netReport__FPCce(const char*, ...);
int fn_800C84FC();
void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
void* fn_8014C180(void*);
void fn_8014C26C(void*, int, int);
void fn_800C8F68(const char*, ...);
extern NameTable lbl_80408500;
extern char lbl_80457158[];
extern int lbl_805A0448;
}

inline const char* errorName(int idx, const char* base) {
    NameTable table = lbl_80408500;
    if (idx < 0 || idx >= 15)
        return base + 0xA78;
    return table.names[idx];
}

extern "C" int fn_800CBCB0(void* self, int* arg1) {
    const char* base = lbl_80457158;
    int idx = fn_800CC070((u8*)self, arg1);
    if (idx == 0)
        return idx;
    int r = fn_800CC2C0(self);
    if (!((State*)self)->initialized) {
        flushLogToSDCard__Fv();
        if (r != 1) {
            netReport__FPCce(base + 0xA8C, errorName(idx, base), *arg1, r);
            fn_800C8F68(base + 0xAB4, errorName(idx, base), *arg1, r);
            return idx;
        }
        ((u8*)self)[0xFCB] |= 0x80;
        if (fn_800C84FC() && lbl_805A0448 == 0) {
            void* obj = __nw__FUlQ25Heaps8HeapType(0x48, 6);
            if (obj) obj = fn_8014C180(obj);
            if (obj) fn_8014C26C(obj, 6, 1);
        }
    }
    if (lbl_805A0448 != 0) {
        netReport__FPCce(base + 0xAD8);
        return 0;
    }
    netReport__FPCce(base + 0xA8C, errorName(idx, base), *arg1, r);
    fn_800C8F68(base + 0xAB4, errorName(idx, base), *arg1, r);
    return idx;
}