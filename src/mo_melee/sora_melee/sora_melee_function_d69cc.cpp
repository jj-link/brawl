#pragma force_active on

typedef int s32;
typedef short s16;

extern "C" void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
extern "C" void __dl__FPv(void*);
extern "C" void fn_27_84458(void*, int);
extern "C" char lbl_27_data_26028[];
extern "C" void* getInstance__13soEventSystemFv();
extern "C" void* getManager__13soEventSystemFl(void*, long);

struct EventManager {
    virtual void dummy();
    virtual void remove(long);
};

struct S {
    void* vt;
    s16 a;
    s16 b;
};

extern "C" void* fn_27_D69CC(S* self, s32 del) {
    if (self != 0) {
        if ((char*)self + 0xc != 0 && (char*)self + 0x1c != 0) {
            __destroy_arr((char*)self + 0x28, fn_27_84458, 0xc, 0x25);
        }
        if (self != 0 && self != 0) {
            s16 idx = self->a;
            self->vt = (void*)lbl_27_data_26028;
            if (idx != -1) {
                EventManager* mgr = (EventManager*)getManager__13soEventSystemFl(
                    getInstance__13soEventSystemFv(), self->a);
                mgr->remove(self->b);
            }
        }
        if (del > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
