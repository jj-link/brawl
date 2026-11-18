#include <types.h>
#pragma force_active on

extern "C" {
void OSCancelAlarm(void*);
void* fn_8018B0D0(void*, int);
void fn_80204E6C(void*, void*);
void* fn_8027A520(void*, int);
void __dl__FPv(void*);
extern void* lbl_8059EE5C;
}

class VObj {
public:
    virtual void m1(int);
    virtual void m2(int);
    virtual void m3(int);
    virtual void m4(int);
    virtual void m5(int);
    virtual void m6(int);
};

struct VBase { char pad[0x1f0]; };
class VObj1f0 : public VBase {
public:
    virtual void m1(int);
};

extern "C" void* fn_8026FAE4(void* self, int arg1) {
    char* s = (char*)self;
    if (self != 0) {
        ((VObj*)*(void**)(s + 0x1fc))->m1(-1);
        fn_80204E6C(lbl_8059EE5C, *(void**)(s + 0x1fc));
        ((VObj*)*(void**)(s + 0x1e8))->m1(-1);
        fn_80204E6C(lbl_8059EE5C, *(void**)(s + 0x1e8));
        if (*(int*)(*(char**)(s + 4) + 0x20) == 0) {
            int i;
            char* p;
            p = s;
            i = 0;
            do {
                ((VObj*)*(void**)(p + 0x1ec))->m1(-1);
                fn_80204E6C(lbl_8059EE5C, *(void**)(p + 0x1ec));
                i++;
                p += 4;
            } while (i < 4);
        }
        {
            char* p2 = s;
            int j;
            for (j = 0; j < *(int*)(s + 0xc); j++) {
                ((VObj*)*(void**)(p2 + 0x270))->m1(-1);
                fn_80204E6C(lbl_8059EE5C, *(void**)(p2 + 0x270));
                p2 += 4;
            }
        }
        {
            char* p2 = s;
            int j;
            for (j = 0; j < 0xf; j++) {
                ((VObj*)*(void**)(p2 + 0x3c8))->m1(-1);
                fn_80204E6C(lbl_8059EE5C, *(void**)(p2 + 0x3c8));
                p2 += 4;
            }
        }
        {
            char* p2 = s;
            int j;
            for (j = 0; j < 0x4a; j++) {
                ((VObj*)*(void**)(p2 + 0x2a0))->m1(-1);
                fn_80204E6C(lbl_8059EE5C, *(void**)(p2 + 0x2a0));
                p2 += 4;
            }
        }
        fn_80204E6C(lbl_8059EE5C, *(void**)(s + 0x204));
        ((VObj*)*(void**)(s + 0x200))->m6(-1);
        fn_80204E6C(lbl_8059EE5C, *(void**)(s + 0x200));
        {
            char* p2 = s;
            int j;
            for (j = 0; j < 4; j++) {
                fn_8027A520(*(void**)(p2 + 0x25c), -1);
                fn_80204E6C(lbl_8059EE5C, *(void**)(p2 + 0x25c));
                p2 += 4;
            }
        }
        ((VObj1f0*)*(void**)(s + 0x26c))->m1(-1);
        fn_80204E6C(lbl_8059EE5C, *(void**)(s + 0x26c));
        *(void**)(s + 0x26c) = 0;
        fn_80204E6C(lbl_8059EE5C, *(void**)(s + 0xa8));
        fn_80204E6C(lbl_8059EE5C, *(void**)(s + 0xac));
        {
            char* b;
            char* a;
            int k;
            a = s + 0x418;
            b = s + 0x4d8;
            for (k = 0; k < 4; k++) {
                OSCancelAlarm(a);
                OSCancelAlarm(b);
                a += 0x30;
                b += 0x30;
            }
        }
        OSCancelAlarm(s + 0x598);
        fn_8018B0D0(s + 0x208, -1);
        if (arg1 > 0) {
            __dl__FPv(s);
        }
    }
    return self;
}
