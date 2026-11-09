#include <so/stageobject.h>
#pragma force_active on
extern "C" int fn_27_8CC10(void*);
extern "C" void fn_27_1DB0F0(void*, int*, int, StageObject*, int);
struct Link {
    virtual void f00(); virtual void f01(); virtual void f02(); virtual void f03();
    virtual void f04(); virtual void f05(); virtual void f06(); virtual void f07();
    virtual void f08(); virtual int f09(int);
    virtual void f10(); virtual void f11(); virtual void f12(); virtual void f13();
    virtual void f14(); virtual void f15(); virtual void f16(); virtual void f17();
    virtual void f18(); virtual void f19(); virtual void f20(); virtual void f21();
    virtual void f22(); virtual void f23(); virtual void f24(); virtual void f25();
    virtual void f26(); virtual void f27(); virtual void f28(); virtual void f29();
    virtual void f30(); virtual void f31(); virtual void f32(); virtual void f33();
    virtual void f34(); virtual void f35(); virtual void f36(); virtual void f37();
    virtual void f38(); virtual void f39(); virtual void f40(); virtual void f41();
    virtual unsigned int f42(int);
};
struct Work {
    virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3(); virtual void f4();
    virtual void f5(int,int);
};
struct Mid { char pad[0x54]; Link* a; char pad2[0xc]; Work* b; };
struct Outer { char pad[0xd8]; Mid* mid; };
struct Self { char pad[0x60]; Outer* outer; };
extern "C" void fn_94_1D260(void* self, int* arg1, int arg2, StageObject* arg3, int arg4) {
    Self* s = static_cast<Self*>(self);
    Link* a = s->outer->mid->a;
    if (arg3->soGetKind() == 0 && arg3->soGetSubKind() == 0x18 && a->f09(3)) {
        unsigned int id = arg3->m_taskId;
        unsigned int other = a->f42(3);
        if (other != id) goto end;
        {
            switch (*arg1) {
            case 0x455:
            int v = -1;
            switch (fn_27_8CC10(arg3)) {
            case 0x1d5: v = 3; break;
            case 0x1d6: v = 4; break;
            case 0x1dc: v = 5; break;
            case 0x1dd: v = 6; break;
            }
            s->outer->mid->b->f5(v, 0x10000009);
            break;
            }
        }
    }
end:
    fn_27_1DB0F0(self, arg1, arg2, arg3, arg4);
}