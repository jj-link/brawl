#include <types.h>
#pragma force_active on

extern "C" int __cntlzw(unsigned int);

struct TimerEntry {
    const char* name;
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
extern char lbl_804104B8[];
extern float lbl_805A4098;

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual float slot4(void*);
};

class Collection {
public:
    virtual void slot0();
    virtual void slot1();
    virtual int slot2();
    virtual int slot3(int);
    virtual Object_vptr_0* slot4(int, void*);
};

struct Self {
    char pad[0xc];
    Collection obj;
};

extern "C" float fn_802D0440(Self* self, void* arg2) {
    {
        Timer* timer = &lbl_80532448;
        signed char c = (signed char)(
            ((unsigned int)timer->end <<
             __cntlzw((unsigned int)timer->end ^
                      (unsigned int)timer->current)) >> 31);
        if (((unsigned int)(-c | c) >> 31) != 0) {
            TimerEntry* entry = timer->current;
            entry->name = lbl_804104B8 + 0x2f;
            register u32 t;
            asm { mftb t }
            entry->time = t;
            timer->current = entry + 1;
        }
    }

    __attribute__((aligned(16))) unsigned char buffer[0x200];
    float result = lbl_805A4098;
    int iter = self->obj.slot2();

    while ((unsigned int)(iter + 0x10000) != 0xffff) {
        Object_vptr_0* shape = self->obj.slot4(iter, buffer);
        float val = shape->slot4(arg2);
        result = result > val ? result : val;
        iter = self->obj.slot3(iter);
    }

    {
        Timer* timer = &lbl_80532448;
        signed char c = (signed char)(
            ((unsigned int)timer->end <<
             __cntlzw((unsigned int)timer->end ^
                      (unsigned int)timer->current)) >> 31);
        if (((unsigned int)(-c | c) >> 31) != 0) {
            TimerEntry* entry = timer->current;
            entry->name = lbl_804104B8 + 0x0f;
            register u32 t;
            asm { mftb t }
            entry->time = t;
            timer->current = entry + 1;
        }
    }

    return result;
}
