#pragma force_active on
#pragma fp_contract on

#include <types.h>

struct Vec4 {
    float x, y, z, w;
} __attribute__((aligned(16)));

struct Matrix {
    Vec4 a, b, c, d;

    Matrix() {}
    Matrix(const Matrix& other) { *this = other; }

    Matrix& operator=(const Matrix& other) {
        a.x = other.a.x; a.y = other.a.y; a.z = other.a.z; a.w = other.a.w;
        b.x = other.b.x; b.y = other.b.y; b.z = other.b.z; b.w = other.b.w;
        c.x = other.c.x; c.y = other.c.y; c.z = other.c.z; c.w = other.c.w;
        d.x = other.d.x; d.y = other.d.y; d.z = other.d.z; d.w = other.d.w;
        return *this;
    }
};

inline void copyMatrix(Matrix* n, const Matrix* mat) {
    Vec4 md, mc, mb, ma;
    ma.x = mat->a.x; ma.y = mat->a.y; ma.z = mat->a.z; ma.w = mat->a.w;
    mb.x = mat->b.x; mb.y = mat->b.y; mb.z = mat->b.z; mb.w = mat->b.w;
    mc.x = mat->c.x; mc.y = mat->c.y; mc.z = mat->c.z; mc.w = mat->c.w;
    md.x = mat->d.x; md.y = mat->d.y; md.z = mat->d.z; md.w = mat->d.w;
    n->a.x = ma.x; n->a.y = ma.y; n->a.z = ma.z; n->a.w = ma.w;
    n->b.x = mb.x; n->b.y = mb.y; n->b.z = mb.z; n->b.w = mb.w;
    n->c.x = mc.x; n->c.y = mc.y; n->c.z = mc.z; n->c.w = mc.w;
    n->d.x = md.x; n->d.y = md.y; n->d.z = md.z; n->d.w = md.w;
}

struct Shape {
    float pad[3];
    float radius;
    Vec4 points[3];
};

struct Body {
    Shape* shape;
    void* unused;
    Matrix* transform;
};

struct Settings {
    char pad[8];
    float threshold;
};

struct Contact {
    Vec4 position;
    Vec4 normal;
};

struct Entry {
    Vec4 position;
    Vec4 normal;
    u16 id;
    char pad[14];
};

struct Header {
    char pad[2];
    u8 count;
};

struct DeferredEntry {
    Entry* entry;
    Header* header;
    u16* ids;
};

struct Deferred {
    DeferredEntry* entries;
    Entry** selected;
};

struct Context {
    Entry* entries;
    char pad[0x304c];
    Deferred* deferred;
};

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual u16 slot2(Body*, Body*, Settings*, Context*, int, Contact*);
    virtual int slot3(int);
    virtual void slot4(u16);
};

struct Input {
    Body* first;
    Body* second;
    Settings* settings;
    Object_vptr_0* manager;
};

struct TraceEntry {
    const char* name;
    u32 time;
    u32 unused;
};

struct Trace {
    void* start;
    TraceEntry* current;
    void* unused;
    TraceEntry* end;
};

extern "C" int __cntlzw(unsigned int);
extern Trace lbl_80532448;
extern char lbl_80414140[];
extern float lbl_805A4558;
extern float lbl_805A455C;

extern "C" void fn_80323788(
    Vec4*, Vec4*, void*, int, Contact*, float, float, float);

extern "C" u16* fn_802FBF78(
    Input* input, Header* header, u16* ids, Vec4* output, Context* context)
{
    {
        Trace* trace = &lbl_80532448;
        s8 enabled = (s8)(((u32)trace->end <<
            __cntlzw((u32)trace->end ^ (u32)trace->current)) >> 31);
        if (((u32)(-enabled | enabled) >> 31) != 0) {
            TraceEntry* p = trace->current;
            p->name = lbl_80414140;
            register u32 t;
            asm { mftb t }
            p->time = t;
            trace->current = p + 1;
        }
    }

    u32 contactBase;
    int count = 0;
    int selected;
    Body* first = input->first;
    Body* second = input->second;
    Shape* firstShape = first->shape;
    Shape* secondShape = second->shape;

    Vec4 secondPoints[3];
    Matrix firstMatrix;
    copyMatrix(&firstMatrix, first->transform);

    Vec4 firstPoints[2];
    for (int i = 0; i < 2; ++i) {
        int j = i * 4;
        float* dst = (float*)firstPoints + j;
        const float* src = (const float*)firstShape->points + j;
        float x = src[0], z = src[2], y = src[1];
        dst[0] = firstMatrix.d.x +
            (x * firstMatrix.a.x + y * firstMatrix.b.x + z * firstMatrix.c.x);
        dst[1] = firstMatrix.d.y +
            (x * firstMatrix.a.y + y * firstMatrix.b.y + z * firstMatrix.c.y);
        dst[2] = firstMatrix.d.z +
            (x * firstMatrix.a.z + y * firstMatrix.b.z + z * firstMatrix.c.z);
        dst[3] = lbl_805A4558;
    }

    Matrix secondMatrix;
    copyMatrix(&secondMatrix, second->transform);

    const Vec4* trianglePoints = secondShape->points;
    for (int i = 0; i < 3; ++i) {
        int j = i * 4;
        float* dst = (float*)secondPoints + j;
        const float* src = (const float*)trianglePoints + j;
        float x = src[0], z = src[2], y = src[1];
        dst[0] = secondMatrix.d.x +
            (x * secondMatrix.a.x + y * secondMatrix.b.x + z * secondMatrix.c.x);
        dst[1] = secondMatrix.d.y +
            (x * secondMatrix.a.y + y * secondMatrix.b.y + z * secondMatrix.c.y);
        dst[2] = secondMatrix.d.z +
            (x * secondMatrix.a.z + y * secondMatrix.b.z + z * secondMatrix.c.z);
        dst[3] = lbl_805A4558;
    }

    Contact contacts[3];
    fn_80323788(firstPoints, secondPoints, (char*)ids + 8, 1, contacts,
                firstShape->radius, secondShape->radius, lbl_805A455C);

    float distance0 = contacts[0].normal.w;
    float distance1 = contacts[1].normal.w;
    if (distance0 < distance1) {
        selected = 0;
        *output = contacts[0].normal;
    } else {
        selected = 1;
        *output = contacts[1].normal;
    }

    contactBase = (u32)contacts;
    for (int i = 0; i < 3; ++i) {
        u16 id = *(u16*)((u32)ids + i * sizeof(u16));
        const f32 threshold = *(const f32*)(*(const u32*)((const char*)input + 8) + 8);
        if (*(const f32*)((u32)contacts + (i * sizeof(Contact) + 0x1c)) < threshold) {
            if (id == 0xffff) {
                if (context->deferred != 0) {
                    if (input->manager->slot3(1) == 0) {
                        DeferredEntry* entry = context->deferred->entries++;
                        entry->entry = context->entries;
                        entry->ids = ids;
                        entry->header = header;
                        goto emit_contact;
                    }
                } else {
                    id = input->manager->slot2(
                        input->first, input->second, input->settings,
                        context, 0,
                        (Contact*)((u32)contacts + i * sizeof(Contact)));
                }
            }
            if (id != 0xffff) {
            emit_contact:
                Entry* entry = context->entries;
                ++count;
                context->entries = entry + 1;
                entry->position =
                    ((Contact*)((u32)contacts + i * sizeof(Contact)))->position;
                entry->normal = *(const Vec4*)(
                    (u32)contacts + (i * sizeof(Contact) + sizeof(Vec4)));
                entry->id = id;
                if (i == selected && context->deferred != 0) {
                    *context->deferred->selected++ = entry;
                }
            }
        } else if (id != 0xffff) {
            input->manager->slot4(id);
            id = 0xffff;
        }
        *(u16*)((u32)ids + i * sizeof(u16)) = id;
    }

    header->count = count;

    Trace* trace = &lbl_80532448;
    s8 enabled = (s8)(((u32)trace->end <<
        __cntlzw((u32)trace->end ^ (u32)trace->current)) >> 31);
    if (((u32)(-enabled | enabled) >> 31) != 0) {
        TraceEntry* p = trace->current;
        p->name = lbl_80414140 + 11;
        register u32 t;
        asm { mftb t }
        p->time = t;
        trace->current = p + 1;
    }

    return (u16*)((char*)ids + 0x20);
}
