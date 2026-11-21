#include <types.h>
#pragma force_active on

class SoraSub {
public:
    virtual void destroy(int);
};

struct SoraTmpBuf {
    s32* data;
    s32 count;
    s32 cap;
    bool isOwned() const { return (cap & 0x80000000) == 0; }
    void dealloc();
};

extern "C" {
void OSReport(const char*, ...);
void __dl__FPv(void*);
void fn_20_8290(void*, void*);
void fn_8027CE3C(void*, int);
void fn_8027EABC(void*, void*, unsigned int, int);
extern void* lbl_20_bss_8;
extern char lbl_20_data_38[];
extern char lbl_20_data_58[];
extern char lbl_20_data_6C[];
extern void* lbl_805A0EC8;
}

inline void SoraTmpBuf::dealloc() { fn_8027EABC(lbl_805A0EC8, data, cap * 4, 0x15); }

struct SoraArray8 {
    void* data;
    int count;
    int cap;
    bool isOwned() const { return (cap & 0x80000000) == 0; }
    void dealloc() { fn_8027EABC(lbl_805A0EC8, data, cap * 8, 0x15); }
};

extern "C" void* fn_20_254(void* self, int arg1) {
    char* s = (char*)self;
    if (self != 0) {
        SoraTmpBuf b;
        s32 i;
        s32 off;

        *(void**)s = (void*)lbl_20_data_6C;
        b.data = 0;
        b.count = 0;
        b.cap = 0x80000000;

        {
            SoraSub* sub = *(SoraSub**)(s + 0x10);
            if (sub != 0) {
                if (sub != 0) {
                    sub->destroy(1);
                }
                *(void**)(s + 0x10) = 0;
            }
        }

        i = 0;
        off = 0;
        while (i < *(s32*)(s + 0x8)) {
            char* list = *(char**)(s + 0x4);
            if (*(s32*)(list + off) != 0) {
                if (b.count == (b.cap & 0x3FFFFFFF)) {
                    fn_8027CE3C(&b, 4);
                }
                b.data[b.count++] = *(s32*)(list + off);
            }
            off += 8;
            i++;
        }

        if (b.count > 0) {
            for (i = 0; i < b.count; i++) {
                OSReport(lbl_20_data_38, b.data[i]);
            }
        }

        if (b.isOwned()) {
            b.dealloc();
        }

        b.data = 0;
        b.count = 0;
        b.cap = (b.cap & 0x40000000) | 0x80000000;

        if (((SoraArray8*)(s + 4))->isOwned()) {
            ((SoraArray8*)(s + 4))->dealloc();
        }

        *(void**)(s + 0x4) = 0;
        *(s32*)(s + 0x8) = 0;
        *(s32*)(s + 0xC) = (*(s32*)(s + 0xC) & 0x40000000) | 0x80000000;

        fn_20_8290(lbl_20_bss_8, self);
        OSReport(lbl_20_data_58);

        if (b.isOwned()) {
            b.dealloc();
        }

        if ((s + 4) != 0 && ((SoraArray8*)(s + 4))->isOwned()) {
            ((SoraArray8*)(s + 4))->dealloc();
        }

        if (arg1 > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
