#include <types.h>
#pragma force_active on

extern "C" {
void* fn_8018F340(void*, u32);
void* fn_80190D0C(void**, void*);
void* fn_80190E40(void**, void*);
void* fn_80190EC8(void**, void*);
void* fn_80191C94(void**, void*);
void* fn_801910F0(void**, void*);
void* fn_801911F8(void**, void*);
void* fn_80190B08(void**, void*);
void* fn_80190B44(void**, void*);
void* fn_80190B80(void**, void*);
void* fn_80190BBC(void**, void*);
void* fn_80190984(void**, void*);
void fn_80190A20(void**, int);
void fn_80190A3C(void**, int);
void fn_80190A58(void**, int);
void fn_80190A74(void**, int);
void fn_801909E8(void**, int);
void* fn_801923B0(void**);
}
struct Object {
    char pad[0xe8];
    void* resource;
    char pad2[0x54];
    u32* flags;
    char pad3[8];
    char* a;
    char* b;
    char* c;
    char* d;
    char* e;
    char* f;
    char* g;
    char* h;
    char* i;
    char* j;
    char* k;
};
struct Material {
    char pad[0x38];
    int offset;
};
extern "C" void fn_801B2AE0(Object* self, int index, u32 flags) {
    char* material;
    void* resource = self->resource;
    material = (char*)fn_8018F340(&resource, index);
    if ((flags & 1) && self->a) {
        void* p = material + 0x3c;
        fn_80190D0C(&p, self->a + index * 0x104);
    }
    if ((flags & 2) && self->b) {
        void* p = material + 0x140;
        fn_80190E40(&p, self->b + index * 0x64);
    }
    if ((flags & 4) && self->c) {
        void* p = material + 0x1a4;
        fn_80190EC8(&p, self->c + index * 0x248);
    }
    if ((flags & 8) && self->d) {
        void* p = material + 0x3ec;
        fn_80191C94(&p, self->d + index * 0x28);
    }
    if ((flags & 0x10) && self->e) {
        void* p = material + 0x14;
        fn_801910F0(&p, self->e + index * 8);
    }
    if ((flags & 0x20) && self->f) {
        void* p = material + 0x1c;
        fn_801911F8(&p, self->f + index * 0xc);
    }
    if ((flags & 0x80) && self->g) {
        int offset = ((Material*)material)->offset;
        void* q;
        void* p = offset ? material + offset : 0;
        q = fn_80190B08(&p, self->g + index * 0x20);
        fn_80190A20(&q, 0);
    }
    if ((flags & 0x100) && self->h) {
        int offset = ((Material*)material)->offset;
        char* base = offset ? material + offset : 0;
        void* q;
        void* p = base + 0x20;
        q = fn_80190B44(&p, self->h + index * 0x80);
        fn_80190A3C(&q, 0);
    }
    if ((flags & 0x200) && self->i) {
        int offset = ((Material*)material)->offset;
        char* base = offset ? material + offset : 0;
        void* q;
        void* p = base + 0xa0;
        q = fn_80190B80(&p, self->i + index * 0x40);
        fn_80190A58(&q, 0);
    }
    if ((flags & 0x400) && self->j) {
        int offset = ((Material*)material)->offset;
        char* base = offset ? material + offset : 0;
        void* q;
        void* p = base + 0xe0;
        q = fn_80190BBC(&p, self->j + index * 0xa0);
        fn_80190A74(&q, 0);
    }
    if ((flags & 0x800) && self->k) {
        void* q;
        void* p = fn_801923B0((void**)&material);
        q = fn_80190984(&p, self->k + index * 0x200);
        fn_801909E8(&q, 0);
    }
    self->flags[index] &= ~flags;
}