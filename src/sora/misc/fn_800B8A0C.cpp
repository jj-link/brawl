#pragma force_active on

extern "C" void __dl__FPv(void*);
extern "C" void fn_800B881C(void*, unsigned char);
extern "C" void fn_803F0D4C(void*, void (*)(void*, int));
extern "C" void fn_800B8AC8(void*, int);
extern "C" void free__13gfHeapManagerFPv(void*);
extern unsigned char lbl_8049E01C[0x14];

struct Pre { char pad[0xA0]; };
class Obj : public Pre {
public:
    virtual void m0(int);
    virtual void m1();
};

struct Wrapper {
    unsigned char flags;
    unsigned char heapType;
    unsigned char pad[2];
    void* buffer;
    Obj* obj8;
    void* array;
};

extern "C" Wrapper* fn_800B8A0C(Wrapper* self, int flag)
{
    if (self) {
        if (self->heapType != 0xff) {
            fn_800B881C(&lbl_8049E01C, self->heapType);
        }
        if (self->buffer != 0 && !((self->flags >> 7) & 1)) {
            free__13gfHeapManagerFPv(self->buffer);
        }
        if (self->array != 0) {
            fn_803F0D4C(self->array, fn_800B8AC8);
        }
        if (self->obj8 != 0) {
            self->obj8->m0(1);
        }
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
