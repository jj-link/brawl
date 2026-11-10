#include <revolution/OS/OSMutex.h>
#pragma force_active on

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2(void*);
};

struct State {
    char pad0[0x74];
    char node1[12];
    char node2[12];
    unsigned char flag1;
    unsigned char flag2;
    char pad8e[6];
    float rate;
    char pad98[4];
    int count;
    float value;
    char pada4[6];
    unsigned char a;
    char padab;
    unsigned short b;
    char padae[6];
    Object_vptr_0* owner;
    void* items[16];
    char padf8[0x20];
    int ticks;
};

extern "C" {
void fn_801C50D0(void*, int);
void fn_801C56D8(void*);
int fn_801C3ABC(State*, int);
char* fn_801CC2E4();
void fn_801CC818(void*, void*);
void* fn_801BE7BC();
void fn_801BE8D0(void*, void*);
void fn_801C4DEC(void*);
extern const float lbl_805A3590;
extern const float lbl_805A3580;
extern const float lbl_805A3584;
}

extern "C" void fn_801C3FA0(State* s) {
    int j;
    int i = 0;
    State* cursor = s;
    do {
        void* p = i > 15 ? 0 : cursor->items[0];
        if (p) {
            fn_801C50D0(p, 127);
            fn_801C56D8(p);
        }
        i++;
        cursor = (State*)((char*)cursor + 4);
    } while (i < 16);

    int n = 0;
    while (0 != s->count ||
           s->value * ((s->rate * (float)(s->a * s->b)) / lbl_805A3590) >= lbl_805A3580) {
        if (n >= 0x300)
            return;

        if (s->count != 0)
            s->count--;
        else
            s->value -= lbl_805A3580 / ((s->rate * (float)(s->a * s->b)) / lbl_805A3590);

        if (fn_801C3ABC(s, 0)) {
            OSLockMutex((OSMutex*)(fn_801CC2E4() + 0x354));

            if (s->flag2) {
                j = (int)s;
                if (s)
                    j = (int)s->node2;
                fn_801CC818(fn_801CC2E4(), (void*)j);
                s->flag2 = 0;
            }

            if (s->flag1) {
                j = (int)s;
                if (s)
                    j = (int)s->node1;
                fn_801BE8D0(fn_801BE7BC(), (void*)j);
                s->flag1 = 0;
            }

            State* iter = s;
            j = 0;
            do {
                OSLockMutex((OSMutex*)(fn_801CC2E4() + 0x354));
                void* p = j > 15 ? 0 : iter->items[0];
                if (p == 0) {
                    OSUnlockMutex((OSMutex*)(fn_801CC2E4() + 0x354));
                } else {
                    fn_801C4DEC(p);
                    s->owner->slot2(iter->items[0]);
                    iter->items[0] = 0;
                    OSUnlockMutex((OSMutex*)(fn_801CC2E4() + 0x354));
                }
                j++;
                iter = (State*)((char*)iter + 4);
            } while (j < 16);

            OSUnlockMutex((OSMutex*)(fn_801CC2E4() + 0x354));
            return;
        }

        n++;
        s->ticks++;
    }

    s->value = lbl_805A3584;
}
