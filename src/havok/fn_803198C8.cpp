#pragma force_active on
#include <../../hk410/include/hkmath/hkMath.h>

struct Vec { float v[4]; } __attribute__((aligned(16)));
class Class_8042B6D0 {
public:
    virtual void fn_8004805C();
    virtual void fn_8004781C();
    virtual void fn_80046A28();
    virtual void fn_8004810C();
    virtual void fn_800480DC();
    virtual void fn_801AB1C4();
    virtual void fn_801B269C();
    virtual void fn_801B26E4();
    virtual void fn_801AAFDC();
    virtual void fn_801AAFE8();
    virtual void fn_801AB290(Vec*, Vec*);
};
struct State {
    int countA, countB, limitA, limitB;
    int flag, changed;
    char pad[8];
    Vec a[4];
    char pad2[0x40];
    Vec b[4];
    Vec localB[4];
    Vec dir;
    char pad3[0x40];
    int status;
};
extern float lbl_805A46D0;
extern float lbl_805A46D4;
extern "C" {
void fn_80319E10(void*, Vec*, int, Vec*);
int fn_8031A180(State*);
float fn_80294C3C(Vec*);
void fn_802DB598(Vec*);
void fn_80294764(Vec*, Vec*, Vec*);
float fn_80294C58(Vec*, Vec*);
int fn_802A0BD8(int*);
void fn_8031B0F4(State*, Class_8042B6D0*, Class_8042B6D0*, void*);
void fn_802F2E90(Vec*, Vec*);
float fn_8031AAC4(Vec*, Vec*, Vec*);
void fn_80318BD0(State*, int, int);
void* fn_802DB624(void*);
void fn_80304A74(Vec*, void*, Vec*);
void fn_802DB59C(Vec*, void*, Vec*);
void fn_80294C80(Vec*);
void fn_80294740(Vec*, Vec*);
float* fn_800966A4(Vec*, int);
}
extern "C" int fn_803198C8(State* s, Class_8042B6D0* a, Class_8042B6D0* b, void* transform, Vec* out) {
    fn_80319E10(transform, s->localB, s->countB, s->b);
    float multiplier;
    float epsilon = lbl_805A46D0;
    int done;
    int iteration = 0;
    multiplier = lbl_805A46D4;
    for (;;) {
        epsilon *= multiplier;
        int oldCount = s->countA + s->countB;
        ++iteration;
        done = fn_8031A180(s);
        float length = fn_80294C3C(&s->dir);
        s->changed |= s->countA + s->countB - oldCount;
        Vec diff;
        fn_802DB598(&diff);
        fn_80294764(&diff, s->a, s->b);
        float dot = fn_80294C58(&diff, &s->dir);
        float threshold;
        if (done || dot * hkMath::fabs(dot) <= (threshold = epsilon * length) || length < epsilon) {
            if (!fn_802A0BD8(&s->flag)) {
                fn_8031B0F4(s, a, b, transform);
                break;
            }
            if (s->countA + s->countB > 4) {
                if (s->countA > s->countB) {
                    s->countA = 3;
                    s->countB = 1;
                } else {
                    s->countA = 1;
                    s->countB = 3;
                }
            }
            return 4;
        }
        done = iteration & 1;
        if (done && s->countA != s->limitA && s->status != 8) {
            Vec v;
            fn_802DB598(&v);
            fn_802F2E90(&v, &s->dir);
            a->fn_801AB290(&v, &s->a[s->countA]);
            if (fn_8031AAC4(&v, &s->a[s->countA], &s->a[0]) > threshold) {
                switch (s->countA) {
                case 3:
                    if (fn_8031AAC4(&v, &s->a[s->countA], &s->a[2]) < threshold) break;
                case 2:
                    if (fn_8031AAC4(&v, &s->a[s->countA], &s->a[1]) < threshold) break;
                default:
                    int i = s->countA++;
                    fn_80318BD0(s, 1, i);
                    continue;
                }
            }
        }
        if (s->countB != s->limitB && s->status != -8) {
            Vec v;
            fn_802DB598(&v);
            fn_80304A74(&v, fn_802DB624(transform), &s->dir);
            b->fn_801AB290(&v, &s->localB[s->countB]);
            if (fn_8031AAC4(&v, &s->localB[s->countB], &s->localB[0]) > threshold) {
                switch (s->countB) {
                case 3:
                    if (fn_8031AAC4(&v, &s->localB[s->countB], &s->localB[2]) < threshold) break;
                case 2:
                    if (fn_8031AAC4(&v, &s->localB[s->countB], &s->localB[1]) < threshold) break;
                default:
                    fn_802DB59C(&s->b[s->countB], transform, &s->localB[s->countB]);
                    int i = s->countB++;
                    fn_80318BD0(s, 1, i);
                    continue;
                }
            }
        }
        if (!done && s->countA != s->limitA && s->status != 8) {
            Vec v;
            fn_802DB598(&v);
            fn_802F2E90(&v, &s->dir);
            a->fn_801AB290(&v, &s->a[s->countA]);
            if (fn_8031AAC4(&v, &s->a[s->countA], &s->a[0]) > threshold) {
                switch (s->countA) {
                case 3:
                    if (fn_8031AAC4(&v, &s->a[s->countA], &s->a[2]) < threshold) break;
                case 2:
                    if (fn_8031AAC4(&v, &s->a[s->countA], &s->a[1]) < threshold) break;
                default:
                    int i = s->countA++;
                    fn_80318BD0(s, 1, i);
                    continue;
                }
            }
        }
        break;
    }
    Vec diff;
    fn_802DB598(&diff);
    fn_80294764(&diff, s->a, s->b);
    fn_80294C80(&s->dir);
    fn_80294740(out, &s->dir);
    float dot = fn_80294C58(&diff, &s->dir);
    *fn_800966A4(out, 3) = dot;
    *fn_800966A4(&s->dir, 3) = dot;
    return 0;
}
