#include <types.h>
#pragma force_active on

extern "C" {
u32 fn_8018F394(void*);
void* fn_8018F340(void*, u32);
u32 GetResNodeNumEntries__Q34nw4r3g3d6ResMdlFv(void*);
void* GetResNode__Q34nw4r3g3d6ResMdlCFUl(void*, u32);
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
void* fn_801923B0(void**);
void fn_80190A20(void**, int);
void fn_80190A3C(void**, int);
void fn_80190A58(void**, int);
void fn_80190A74(void**, int);
void fn_801909E8(void**, int);
}

struct Object {
    char pad[0xe8];
    void* resource;
    char pad2[0x140 - 0xec];
    void* intArray;
    char pad3[4];
    u8* nodeFlags;
    void* b;
    void* c;
    void* d;
    void* e;
    void* f;
    void* g;
    void* h;
    void* i;
    void* j;
    void* k;
    void* l;
};

extern "C" void fn_801B272C(void* self_) {
    Object* self = (Object*)self_;

    void* sp4C;
    void* sp48;

    u32 i;
    int v1;

    int off_arr, off_b, off_c, off_d, off_e, off_f, off_g, off_h, off_i, off_j, off_k, off_l, loop_var;

    sp4C = self->resource;
    u32 countMat = fn_8018F394(&sp4C);
    u32 countNode = GetResNodeNumEntries__Q34nw4r3g3d6ResMdlFv(&sp4C);

    if (self->nodeFlags) {
        i = 0;
        if (countNode) {
            while (i < countNode) {
                void* node = GetResNode__Q34nw4r3g3d6ResMdlCFUl(&sp4C, i);
                if (node)
                    v1 = (*(u32*)((u8*)node + 0x14) >> 8) & 1;
                else
                    v1 = 0;
                if (v1)
                    *(u8*)((u8*)self->nodeFlags + i) = 1;
                else
                    *(u8*)((u8*)self->nodeFlags + i) = 0;
                i++;
            }
        }
    }

    loop_var = 0;
    off_arr = 0;
    off_b = 0;
    off_c = 0;
    off_d = 0;
    off_e = 0;
    off_f = 0;
    off_g = 0;
    off_h = 0;
    off_i = 0;
    off_j = 0;
    off_k = 0;
    off_l = 0;

    while ((u32)loop_var < countMat) {
        char* material = (char*)fn_8018F340(&sp4C, (u32)loop_var);
        sp48 = material;
        *(int*)((char*)self->intArray + off_arr) = 0;

        if (self->b) {
            void* p = material + 0x3c;
            fn_80190D0C(&p, (char*)self->b + off_b);
        }
        if (self->c) {
            void* p = material + 0x140;
            fn_80190E40(&p, (char*)self->c + off_c);
        }
        if (self->d) {
            void* p = material + 0x1a4;
            fn_80190EC8(&p, (char*)self->d + off_d);
        }
        if (self->e) {
            void* p = material + 0x3ec;
            fn_80191C94(&p, (char*)self->e + off_e);
        }
        if (self->f) {
            void* p = material + 0x14;
            fn_801910F0(&p, (char*)self->f + off_f);
        }
        if (self->g) {
            void* p = material + 0x1c;
            fn_801911F8(&p, (char*)self->g + off_g);
        }
        if (self->h) {
            void* q;
            int offset = *(int*)(material + 0x38);
            void* p = offset ? material + offset : 0;
            q = fn_80190B08(&p, (char*)self->h + off_h);
            fn_80190A20(&q, 0);
        }
        if (self->i) {
            void* q;
            int offset = *(int*)(material + 0x38);
            char* base = offset ? material + offset : 0;
            void* p = base + 0x20;
            q = fn_80190B44(&p, (char*)self->i + off_i);
            fn_80190A3C(&q, 0);
        }
        if (self->j) {
            void* q;
            int offset = *(int*)(material + 0x38);
            char* base = offset ? material + offset : 0;
            void* p = base + 0xa0;
            q = fn_80190B80(&p, (char*)self->j + off_j);
            fn_80190A58(&q, 0);
        }
        if (self->k) {
            void* q;
            int offset = *(int*)(material + 0x38);
            char* base = offset ? material + offset : 0;
            void* p = base + 0xe0;
            q = fn_80190BBC(&p, (char*)self->k + off_k);
            fn_80190A74(&q, 0);
        }
        if (self->l) {
            void* q;
            void* p = fn_801923B0((void**)&material);
            q = fn_80190984(&p, (char*)self->l + off_l);
            fn_801909E8(&q, 0);
        }

        off_arr += 4;
        off_b += 0x104;
        off_c += 0x64;
        off_d += 0x248;
        off_e += 0x28;
        off_f += 8;
        off_g += 0xc;
        off_h += 0x20;
        off_i += 0x80;
        off_j += 0x40;
        off_k += 0xa0;
        off_l += 0x200;
        loop_var += 1;
    }
}
