#include <types.h>

#pragma force_active on

extern "C" int __cntlzw(unsigned int);

struct TimerEntry {
    char* name;
    unsigned int time;
    unsigned int unused;
};

struct Timer {
    unsigned int unused0;
    TimerEntry* current;
    unsigned int unused8;
    TimerEntry* end;
    unsigned int unused10[2];
};

extern Timer lbl_80532448;
extern char lbl_80410580[];

inline void record(int offset)
{
    Timer* timer = &lbl_80532448;
    TimerEntry* end = timer->end;
    TimerEntry* entry = timer->current;
    signed char flag = (signed char)(((unsigned int)end <<
        __cntlzw((unsigned int)end ^ (unsigned int)entry)) >> 31);

    if (((unsigned int)(-(int)flag | (int)flag) >> 31) != 0) {
        entry->name = lbl_80410580 + offset;
        register u32 t;
        asm { mftb t }
        entry->time = t;
        timer->current = entry + 1;
    }
}

struct InputBlock {
    float f0, f4, f8, fC;
    float f10, f14, f18, f1C;
    unsigned int v20, v24;
};

struct Context {
    unsigned char pad[0x18];
    unsigned int entries[8];
    int count;
};

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual unsigned int slot5(const float*, Context*);
};

class Class_80487490 {
public:
    virtual void fn_802D0AD4();
    virtual void fn_802D1434();
    virtual void fn_802D0BDC();
    virtual void fn_802D0BE4();
    virtual void fn_802D0D10();
    virtual void fn_802D0D80();
};

extern "C" int fn_802D0D80(void* arg0, const InputBlock* arg1, Context* arg2)
{
    __attribute__((aligned(16))) float local[10];
    Object_vptr_0* object;
    unsigned char top;

    record(0);

    local[0] = arg1->f0;
    local[1] = arg1->f4;
    local[2] = arg1->f8;
    local[3] = arg1->fC;
    local[4] = arg1->f10;
    local[5] = arg1->f14;
    local[6] = arg1->f18;
    local[7] = arg1->f1C;
    *(unsigned int*)((char*)local + 0x20) = arg1->v20;
    *(unsigned int*)((char*)local + 0x24) = arg1->v24;

    local[0] = local[0] - *(float*)((char*)arg0 + 0x20);
    local[1] = local[1] - *(float*)((char*)arg0 + 0x24);
    local[2] = local[2] - *(float*)((char*)arg0 + 0x28);
    local[3] = local[3] - *(float*)((char*)arg0 + 0x2C);
    local[4] = local[4] - *(float*)((char*)arg0 + 0x20);
    local[5] = local[5] - *(float*)((char*)arg0 + 0x24);
    local[6] = local[6] - *(float*)((char*)arg0 + 0x28);
    local[7] = local[7] - *(float*)((char*)arg0 + 0x2C);

    arg2->count = arg2->count + 1;
    object = *(Object_vptr_0**)((char*)arg0 + 0x14);
    top = object->slot5(local, arg2) >> 24;
    {
        int n = arg2->count;
        n = n - 1;
        arg2->count = n;

        if (((unsigned int)(-(int)(signed char)top | (int)(signed char)top) >> 31) != 0) {
            arg2->entries[n] = 0;
        }
    }

    record(15);
    return (int)(top << 24);
}