#include <types.h>
#include <nw4r/math/math_types.h>
#pragma force_active on

struct Node {
    char pad0[0xb0];
    float value;
    char padb4[0x110];
    u8 marked;
    char pad1c5[3];
    nw4r::math::VEC3 first;
    char pad1d4[4];
    nw4r::math::VEC3 second;
};
struct Object {
    Node** nodes;
    int count;
    char pad08[4];
    u8 flag0c;
    char pad0d;
    u8 flag0e;
    char pad0f[0x11];
    u8 mode;
    char pad21[0x21];
    u8 active;
    u8 saved;
    char pad44[0x13];
    u8 state;
    char pad58[4];
    u8 flag5c;
    u8 flag5d;
    u8 flag5e;
    char pad5f;
    float value;
    char pad64[4];
    char matrix1[0x30];
    char matrix2[0x30];
    char padc8[0x20];
    u8 flage8;
};
struct Context {
    Object* a;
    Object* b;
    u8 flag8, flag9, flaga;
};
extern "C" {
void fn_8008AD64(Context*);
void fn_80091F28(Object*);
void fn_80091AFC(Object*);
int fn_8008F230(Object*);
void fn_80095990(Object*, int*);
void fn_801EC158(void*);
void fn_801EC868(void*, void*, float, float, float);
extern u8 lbl_8059DC01, lbl_8059DC02, lbl_8059DC03, lbl_8059DC04, lbl_8059DC05, lbl_8059DC06, lbl_8059DC07;
extern const float lbl_805A1CA8;
}
static inline void clearObject(Object* o) {
    for (int i = 0; i < o->count; i++) o->nodes[i]->marked = 0;
    o->flag5c = 0;
}
static inline void clearMarks(Context* self) {
    if (self->a->flag5c || self->b->flag5c) {
        clearObject(self->a);
        if (self->b) clearObject(self->b);
        Object* a = self->a;
        a->flag5c = 0;
        a->flag5d = 0;
        Object* b = self->b;
        b->flag5c = 0;
        b->flag5d = 0;
    }
}
static inline void resetSecond(Object* o) {
    for (int i = 0; i < o->count; i++)
        o->nodes[i]->second = nw4r::math::VEC3(lbl_805A1CA8, lbl_805A1CA8, lbl_805A1CA8);
}
static inline void resetFirst(Object* o) {
    for (int i = 0; i < o->count; i++)
        o->nodes[i]->first = nw4r::math::VEC3(lbl_805A1CA8, lbl_805A1CA8, lbl_805A1CA8);
}
static inline void setMatrices(Object* target, nw4r::math::VEC3 v1, nw4r::math::VEC3 v2) {
    char m[0x30];
    fn_801EC158(m);
    fn_801EC868(m, target->matrix1, v1.x, v1.y, v1.z);
    fn_801EC868(m, target->matrix2, v2.x, v2.y, v2.z);
}
static inline void restore(Object* o) {
    for (int i = 1; i < o->count; i++) {
        if (lbl_805A1CA8 == o->nodes[i]->value)
            o->nodes[i]->value = o->value;
    }
    o->flag0c = 0;
    o->flage8 = 0;
}

extern "C" void fn_8008F3E0(Context* self, int mode) {
    Object* o = self->a;
    if (!o) return;
    if (mode == 2) {
        Object* other = self->b;
        int state = o->state;
        int kind;
        if (other && !o->mode && !other->mode) {
            if (state == 8) kind = 3;
            else kind = 6;
        } else if (state == 0) {
            if (o->flag5c) kind = 4;
            else kind = 0;
        } else if (state == 4) {
            if (o->flag5c) kind = 5;
            else kind = 1;
        } else if (state == 5) {
            kind = 2;
        } else if (state == 6) {
            if (o->flag5c) kind = 5;
            else kind = 1;
        } else if (state == 7) {
            kind = 6;
        } else if (state == 9) {
            kind = 7;
        } else {
            kind = 3;
            if (state == 10) kind = 8;
        }
        if (kind == 6 || state == 8) {
            o->saved = o->active;
            self->flag9 = 1;
            self->flag8 = 0;
            self->flaga = 1;
            self->a->flag0e = 1;
            __memcpy(&self->a->mode, &lbl_8059DC01, sizeof(u8));
        } else if (other) {
            fn_8008AD64(self);
            fn_80091F28(self->b);
        }
        clearMarks(self);
    } else if (mode == 1) {
        resetSecond(o);
        resetFirst(self->a);
        if (self->b) {
            if ((int)self->a->state == 5) {
                fn_8008AD64(self);
            } else {
                fn_80091F28(self->a);
                self->a->state = 4;
                if (self->b) self->b->state = 5;
            }
        }
        clearMarks(self);
    } else if (mode == 0) {
        restore(o);
        restore(self->b);
        self->flag8 = 0;
        resetSecond(self->a);
        resetFirst(self->a);
        if ((int)self->a->state == 8) self->a->flag0e = 1;
        self->a->state = 0;
        if (self->b) self->b->state = 0;
        clearMarks(self);
    } else if (mode == 8) {
        resetSecond(o);
        resetFirst(self->a);
        if (self->b) {
            if ((int)self->a->state == 5) {
                fn_8008AD64(self);
            } else {
                fn_80091AFC(self->a);
                fn_80091F28(self->a);
                self->a->state = 10;
                if (self->b) self->b->state = 5;
            }
        }
        clearMarks(self);
    } else if (mode == 7) {
        restore(o);
        restore(self->b);
        self->flag8 = 0;
        resetSecond(self->a);
        resetFirst(self->a);
        setMatrices(self->a,
            nw4r::math::VEC3(lbl_805A1CA8, lbl_805A1CA8, lbl_805A1CA8),
            nw4r::math::VEC3(lbl_805A1CA8, lbl_805A1CA8, lbl_805A1CA8));
        if ((int)self->a->state == 8) self->a->flag0e = 1;
        self->a->state = 9;
        if (self->b) self->b->state = 0;
        clearMarks(self);
        __memcpy(&self->a->mode, &lbl_8059DC02, sizeof(u8));
        if (self->b) self->b->mode = lbl_8059DC03;
    } else if (mode == 3) {
        if ((int)o->state == 5) {
            if (self->b) fn_8008AD64(self);
            clearMarks(self);
        }
        self->a->state = 8;
        __memcpy(&self->a->mode, &lbl_8059DC04, sizeof(u8));
        if (self->b) self->b->mode = lbl_8059DC05;
    } else if (mode == 6) {
        o->mode = lbl_8059DC06;
        if (self->b) self->b->mode = lbl_8059DC07;
    } else if (mode == 4) {
        if (!o->flag5c) {
            o->flag5e = o->count - o->saved;
            int n = o->flag5e;
            fn_80095990(o, &n);
            o->flag5c = 1;
            if (self->b) {
                u8 count = fn_8008F230(self->b);
                Object* b = self->b;
                b->flag5e = count;
                int n2 = count;
                fn_80095990(b, &n2);
                b->flag5c = 1;
            }
        }
    } else if (mode == 5) {
        if (o->flag5c || self->b->flag5c) {
            clearObject(o);
            if (self->b) clearObject(self->b);
        }
        Object* b = self->b;
        b->flag5c = 1;
        b->flag5d = 0;
    }
}
