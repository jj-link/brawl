#include <types.h>
#pragma force_active on

extern "C" void* getNode__6utListFUl(void*, u32);
extern "C" void* fn_27_6F30C(void*);
extern "C" float lbl_27_rodata_940;

struct VA {
    virtual void p0();
    virtual void p1();
    virtual void p2();
    virtual void p3();
    virtual void p4();
    virtual void p5();
    virtual void p6();
    virtual void p7();
    virtual void p8();
    virtual int check(int);
};

struct VB {
    virtual void q0();
    virtual void q1();
    virtual void q2();
    virtual void q3();
    virtual void q4();
    virtual void q5();
    virtual void q6();
    virtual void q7();
    virtual void q8();
    virtual void q9();
    virtual void q10();
    virtual void q11();
    virtual void q12();
    virtual void q13();
    virtual void q14();
    virtual void q15();
    virtual void q16();
    virtual void q17();
    virtual void q18();
    virtual void q19();
    virtual void q20();
    virtual void q21();
    virtual float run();
};

extern "C" float fn_27_6C2E8(void* self) {
    if (((VA*)self)->check(-1) != 0) {
        void* node = getNode__6utListFUl((char*)self + 0x20, 0);
        while (node != 0) {
            void* target = *(void**)((char*)node + 0xc);
            u32 bits = *(u32*)((char*)target + 0x30);
            if (((bits >> 8) & 4) != 0) {
                void* acc = fn_27_6F30C(node);
                void* data = *(void**)((char*)acc + 0x44);
                void* modules = *(void**)((char*)data + 0xd8);
                void* obj = *(void**)((char*)modules + 0xc);
                return ((VB*)obj)->run();
            }
            node = *(void**)node;
        }
    }
    return lbl_27_rodata_940;
}
