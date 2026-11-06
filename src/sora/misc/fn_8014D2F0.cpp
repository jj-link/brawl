#pragma force_active on
#include <revolution/OS/OSTime.h>

typedef unsigned long long u64;

extern "C" int fn_8014DD34(void*, int);
extern "C" int fn_8014E0DC(void*, int);
extern "C" int fn_8039A52C(void);
extern "C" int fn_8039B13C(void*, int*);
extern "C" int fn_8039B1B0(void*, int*);
extern "C" void fn_8039B5AC(int, int);
extern "C" int fn_8039DC18(int);
extern "C" u64 fn_8014F9C8(void);
extern "C" void fn_801E1D80(u64, void*);
extern "C" void fn_8014FA94(u64);
extern "C" int fn_8014FA60(void);
extern "C" void fn_8014FAE4(int);

class Anim {
public:
    virtual void vf1(int, int, int);
};

struct Obj {
    int pad[2];
    Anim* m_anim;
};

struct Cal {
    int v[10];
};

extern "C" int fn_8014D2F0(Obj* arg0, unsigned int arg1, int* arg2) {
    Cal bufA;
    Cal bufB;
    int spC;
    int sp8;
    int* curr;
    int code;
    unsigned int count;
    int acc;
    int found;

    if (fn_8014DD34(arg0, 1) == 0) {
        return 0;
    }

    curr = arg2;
    count = 0;
    acc = 0;
    found = 0;

    for (unsigned int i = 0; i < arg1; i++) {
        code = fn_8039DC18(*curr);
        if (code != 0) {
            if (fn_8014E0DC(arg0, code) != 0) {
                switch (code) {
                case -14: {
                    int v = fn_8039A52C();
                    Anim* o = arg0->m_anim;
                    if (o != 0) {
                        int av = v;
                        if (v < 0) {
                            av = -v;
                        }
                        o->vf1(1, code, av);
                    }
                    break;
                }
                case -8:
                case -6: {
                    int v = fn_8039A52C();
                    Anim* o = arg0->m_anim;
                    if (o != 0) {
                        int av = v;
                        if (v < 0) {
                            av = -v;
                        }
                        o->vf1(8, code, av);
                    }
                    break;
                }
                default: {
                    int v = fn_8039A52C();
                    Anim* o = arg0->m_anim;
                    if (o != 0) {
                        int av = v;
                        if (v < 0) {
                            av = -v;
                        }
                        o->vf1(3, code, av);
                    }
                    break;
                }
                }
            }
            found = 1;
            break;
        }

        spC = 0;
        if (fn_8039B13C((void*)*curr, &spC) == 0) {
            acc += spC;
        }
        count++;
        curr++;
    }

    if (found != 0) {
        int* cleanup = arg2;
        for (unsigned int i = 0; i < count; i++) {
            sp8 = 0;
            if (fn_8039B1B0((void*)*cleanup, &sp8) == 0) {
                fn_8039B5AC(0, sp8);
            }
            cleanup++;
        }
        return 0;
    }

    fn_801E1D80(OSGetTime(), &bufA);
    fn_801E1D80(fn_8014F9C8(), &bufB);
    if (bufB.v[5] == bufA.v[5] && bufB.v[7] == bufA.v[7]) {
        int result = fn_8014FA60();
        result += acc;
        fn_8014FAE4(result);
    } else {
        fn_8014FA94(OSGetTime());
        fn_8014FAE4(acc);
    }
    return 1;
}
