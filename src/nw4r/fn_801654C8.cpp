#include <nw4r/math/math_types.h>
#pragma force_active on

using namespace nw4r::math;

struct Info {
    short a;
    unsigned char b, c, d, e, f, g;
};

struct Config {
    char pad[8];
    unsigned int flags;
    char padc[0x17];
    unsigned char value;
};

struct Owner {
    char pad[0x10];
    int count;
    char pad14[0xa4];
    Config* config;
    void* context;
    char padc0[8];
    void* ptr;
};

struct Obj {
    char pad[0x64];
    unsigned char flags, value;
    char pad66[0x2a];
    VEC3 pos;
    VEC3 scale;
    float rot[3];
    char padb4[0x34];
    unsigned short count;
    char padea[0xa];
    Owner* owner;
    Owner* parent;
    Info info;
};

extern "C" {
Obj* fn_80163CE8(void*, int, int, int);
void fn_80166CE8(void*);
void fn_801EC158(MTX34*);
void fn_801629AC(MTX34*, float, float, float);
void fn_801628B4(MTX34*, MTX34*, VEC3*);
void fn_80162908(MTX34*, MTX34*, void*);
void fn_80166B8C(void*, MTX34*);
void fn_801EC41C(MTX34*, MTX34*);
void fn_801EC1B8(MTX34*, MTX34*, MTX34*);
void fn_8016DE48(void*, MTX34*);
extern const float lbl_805A2C88;
extern const float lbl_805A2C8C;
}

static inline void makeRotation(MTX34* m, float x, float y, float z) {
    fn_801629AC(m, lbl_805A2C8C * x, lbl_805A2C8C * y, lbl_805A2C8C * z);
}

extern "C" Obj* fn_801654C8(
    Owner* self, int a, Info* info, Owner* parent, int n
) {
    Obj* obj = fn_80163CE8(self->context, a, info->e, 0);
    if (!obj)
        return 0;

    obj->count += n;
    obj->owner = self;
    self->count++;
    obj->flags = 0;

    if (self->config->flags & 0x80)
        obj->flags |= 1;
    if (self->config->flags & 0x100)
        obj->flags |= 2;

    obj->value = self->config->value;

    if (parent) {
        VEC3 pos = obj->pos;
        obj->pos.x = lbl_805A2C88;
        obj->pos.y = lbl_805A2C88;
        obj->pos.z = lbl_805A2C88;
        fn_80166CE8(obj);

        MTX34 m, tmp;
        fn_801EC158(&m);
        makeRotation(&m, obj->rot[0], obj->rot[1], obj->rot[2]);
        fn_801628B4(&m, &m, &obj->scale);
        fn_80166B8C(obj, &tmp);
        fn_801EC41C(&tmp, &tmp);
        fn_801EC1B8(&m, &tmp, &m);
        fn_8016DE48(parent->ptr, &tmp);
        fn_801EC1B8(&m, &tmp, &m);
        fn_80162908(&m, &m, (char*)parent + 0xac);
        makeRotation(&tmp, obj->rot[0], obj->rot[1], obj->rot[2]);
        fn_801628B4(&tmp, &tmp, &obj->scale);
        fn_801EC41C(&tmp, &tmp);
        fn_801EC1B8(&m, &tmp, &m);

        obj->pos.x = pos.x + m[0][3];
        obj->pos.y = pos.y + m[1][3];
        obj->pos.z = pos.z + m[2][3];
        fn_80166CE8(obj);

        if (info->a || info->b || info->c || info->d || (info->g & 2)) {
            obj->parent = parent;
            parent->count++;
            obj->info.a = info->a;
            obj->info.b = info->b;
            obj->info.c = info->c;
            obj->info.d = info->d;
            obj->info.e = info->e;
            obj->info.f = info->f;
            obj->info.g = info->g;
        }
    }

    return obj;
}
