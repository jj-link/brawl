#pragma force_active on
typedef unsigned short u16;
typedef unsigned int u32;

struct Input {
    u16 id;
    float x, y, z, a, b;
    u32 c, d;
};

struct Owner {
    char pad[0x10];
    void* value;
};

struct Object {
    u32 unk0;
    Owner* owner;
    char pad[0x15];
    unsigned char flags;
};

struct Request {
    void* owner;
    u16 id;
    float x, y, z, a, b;
    u32 c, d;
};

extern void* lbl_27_bss_5780;

extern "C" void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
extern "C" void* fn_27_22A914(void*);
extern "C" void fn_27_22ACB0(void*, Request*);

extern "C" void fn_27_A7778(Object* self, const Input* input) {
    Request request;
    request.owner = self->owner->value;
    request.id = input->id;
    request.x = input->x;
    request.y = input->y;
    request.z = input->z;
    request.a = input->a;
    request.b = input->b;
    request.c = input->c;
    request.d = input->d;

    if (!lbl_27_bss_5780) {
        void* p = __nw__FUlQ25Heaps8HeapType(0x54, 2);
        if (p)
            p = fn_27_22A914(p);
        lbl_27_bss_5780 = p;
    }

    fn_27_22ACB0(lbl_27_bss_5780, &request);
    self->flags |= 0x20;
}
