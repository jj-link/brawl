#include <types.h>
#pragma force_active on

struct Context;
struct Input;
struct Work;

class Class_802F0BEC {
public:
    virtual ~Class_802F0BEC();
    virtual void fn_80080A64();
    virtual void fn_802F12D8();
    virtual void fn_802F0C48();
    virtual void fn_802F0DAC();
    virtual void fn_802F11E0(void*, void*, Input*, Work*);
};

struct Context {
    char pad0[8];
    s8 index;
    char pad9[7];
    Class_802F0BEC* target;
    void* arg14;
    void* arg18;
};

struct Input {
    char* data;
    char pad4[8];
    u8 value;
    char padD[0x1B];
    void* field28;
};

struct Work {
    void* current;
    char pad4[12];
    char storage[0x3020];
    f32 value;
    char pad3034[0x1C];
    int field3050;
};

struct Heap {
    int pad0;
    int status;
    int total;
    char padC[8];
    int used;
    char pad18[0x10];
    int extra;
    int available() {
        int sum = extra + used;
        if (total <= sum) {
        } else {
            return total - sum;
        }
        return 0;
    }
};

extern Heap* lbl_805A0EB8;
extern const f32 lbl_805A4518;
extern "C" int __cntlzw(unsigned int);
extern "C" void fn_802FF784(Context*, Input*, Work*);

extern "C" void fn_802F279C(void*, Context* context, Input* input, Work* work) {
    work->current = work->storage;
    work->value = lbl_805A4518;
    work->field3050 = 0;
    char* data = input->data;
    input->field28 = data + 0x1A64;
    input->value = *(u8*)(data + context->index * 0x3C + 0x1A38);
    fn_802FF784(context, input, work);
    if (lbl_805A0EB8->available() == 0) {
        lbl_805A0EB8->status = 1;
    }
    if (lbl_805A0EB8->status != 1 &&
        (s8)((unsigned int)__cntlzw((unsigned int)((char*)work + 0x10) -
                                    (unsigned int)work->current) >> 5) == 0) {
        context->target->fn_802F11E0(context->arg14, context->arg18, input, work);
    }
}