#pragma force_active on
#include <types.h>

extern "C" {

extern void* lbl_27_bss_2BD8;
void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
void* fn_27_C152C(void*);
void fn_27_C164C(void*, void*, s32);
void fn_27_C16BC(void*, void*, s32);
void fn_27_C1AD8(void*);
void fn_27_C1E74(void*, int);

class VBase {
    int a, b;
};

class VObj : public VBase {
public:
    virtual void* m0(int);
    virtual void* m1(int);
    virtual void* m2(int);
    virtual void* m3(int);
    virtual void* m4(int);
    virtual void* m5(int);
    virtual void* m6(int);
    virtual void* m7(int);
    virtual void* m8(int);
    virtual void* m9(int);
    virtual void* m10(int);
    virtual void* m11(int);
    virtual void* m12(int);
    virtual void* m13(int);
    virtual void* m14(int);
    virtual void* m15(int);
    virtual void* m16(int);
    virtual void* m17(int);
    virtual void* m18(int);
    virtual void* m19(int);
    virtual void* m20(int);
    virtual void* m21(int);
    virtual void* m22(int);
    virtual void* m23(int);
    virtual void* m24(int);
    virtual void* m25(int);
    virtual void* m26(int);
    virtual void* m27(int);
    virtual void* m28(int);
    virtual void* m29(int);
    virtual void* m30(int);
    virtual void* m31(int);
    virtual void* m32(int);
    virtual void* m33(int);
    virtual void* m34(int);
    virtual void* m35(int);
    virtual void* m36(int);
    virtual void* m37(int);
    virtual void* m38(int);
    virtual void* m39(int);
    virtual void* m40(int);
    virtual void* m41(int);
    virtual void* m42(int);
    virtual void* m43(int);
    virtual void* m44(int);
    virtual void* m45(int);
    virtual void* m46(int);
    virtual void* m47(int);
    virtual void* m48(int);
    virtual void* m49(int);
    virtual void* m50(int);
    virtual void* m51(int);
    virtual void* m52(int);
    virtual void* m53(int);
    virtual void* m54(int);
    virtual void* m55(int);
    virtual void* m56(int);
    virtual void* m57(int);
    virtual void* m58(int);
    virtual void* m59(int);
    virtual void* m60(int);
    virtual void* m61(int);
    virtual void* m62(int);
    virtual void* m63(int);
    virtual void* m64(int);
    virtual void* m65(int);
    virtual void* m66(int);
    virtual void* m67(int);
    virtual void* m68(int);
    virtual void* m69(int);
    virtual void* m70(int);
    virtual void* m71(int);
    virtual void* m72(int);
};

void fn_27_C2350(u8* self, s32 arg1) {
    s32 r29;
    if (self[0x4A] == 0) {
        r29 = 0;
        fn_27_C1AD8(self + 0x1C);
        if (self[0x47] == 1) {
            s32 mode = arg1;
            s8 t = (s8)self[0x46];
            if (t != -1) {
                mode = t;
            }
            if (mode == 5) {
                if (self[0x49] == 0) {
                    s32 i;
                    for (i = 0; i < 4; i++) {
                        if (!lbl_27_bss_2BD8) {
                            void* p = __nw__FUlQ25Heaps8HeapType(0xA4, 2);
                            if (p) {
                                p = fn_27_C152C(p);
                            }
                            lbl_27_bss_2BD8 = p;
                        }
                        fn_27_C164C(lbl_27_bss_2BD8, self + 0x1C, i);
                    }
                } else {
                    s32 i;
                    for (i = 0; i < 4; i++) {
                        if (!lbl_27_bss_2BD8) {
                            void* p = __nw__FUlQ25Heaps8HeapType(0xA4, 2);
                            if (p) {
                                p = fn_27_C152C(p);
                            }
                            lbl_27_bss_2BD8 = p;
                        }
                        fn_27_C16BC(lbl_27_bss_2BD8, self + 0x1C, i);
                    }
                }
                r29 = 1;
            } else {
                if (arg1 == 0) {
                    void* A = *(void**)(self + 0x18);
                    void* B = *(void**)((char*)A + 0xD8);
                    void* C = *(void**)((char*)B + 0x10);
                    VObj* vobj = (VObj*)C;
                    *(void**)(self + 0x30) = vobj->m72(0);
                }
                if (self[0x49] == 0) {
                    if (!lbl_27_bss_2BD8) {
                        void* p = __nw__FUlQ25Heaps8HeapType(0xA4, 2);
                        if (p) {
                            p = fn_27_C152C(p);
                        }
                        lbl_27_bss_2BD8 = p;
                    }
                    fn_27_C164C(lbl_27_bss_2BD8, self + 0x1C, mode);
                } else {
                    if (!lbl_27_bss_2BD8) {
                        void* p = __nw__FUlQ25Heaps8HeapType(0xA4, 2);
                        if (p) {
                            p = fn_27_C152C(p);
                        }
                        lbl_27_bss_2BD8 = p;
                    }
                    fn_27_C16BC(lbl_27_bss_2BD8, self + 0x1C, mode);
                }
                r29 = 1;
            }
            self[0x37] = (u8)arg1;
        }
        if (r29 == 0) {
            fn_27_C1E74(self + 0x1C, 0);
        }
    }
}

}