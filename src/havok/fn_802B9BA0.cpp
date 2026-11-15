#include <types.h>

#pragma force_active on
#pragma fp_contract on

extern "C" int __cntlzw(unsigned int);

struct TimerEntry {
    char* name;
    u32 time;
    u32 unused;
};

struct Timer {
    u32 unused0;
    TimerEntry* current;
    u32 unused8;
    TimerEntry* end;
    u32 unused10[2];
};

extern Timer lbl_80532448;
extern char lbl_8040FED0[];
extern float lbl_805A3F80;
extern float lbl_805A3F84;

inline void record(int offset) {
    Timer* timer = &lbl_80532448;
    TimerEntry* entry = timer->current;

    if ((signed char)(((u32)timer->end
                       << __cntlzw((u32)timer->end ^ (u32)entry))
                      >> 31)) {
        entry->name = lbl_8040FED0 + offset;
        register u32 t;
        asm { mftb t }
        entry->time = t;
        timer->current = entry + 1;
    }
}

struct Vec {
    float x, y, z, w;
};

struct Matrix {
    Vec col[4];
};

struct Ray {
    Vec a, b;
};

struct RayIn {
    Vec from, to;
    int filter;
    int unk;
};

struct Shape {
    char pad[12];
    Ray* rays;
    int count;
};

struct Body {
    Shape* shape;
    int key;
    Matrix* transform;
};

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1(Body*, Body*);
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual unsigned int slot5(RayIn*, void*);
};

struct OtherBody {
    Object_vptr_0* shape;
    int key;
    Matrix* transform;
};

class Callback {
public:
    virtual void slot0();
    virtual void slot1(Body*, OtherBody*);
    signed char done;
};

struct Result {
    char pad[16];
    float fraction;
    int key1;
    int key2;
    char pad2[28];
    int field;
    char pad3[4];
};

extern "C" void fn_80287600(Matrix*, const Matrix*, const Matrix*);

inline int keepLooping(int n, Callback* cb) {
    int r = 0;
    if (n != 0 && !cb->done) {
        r = 1;
    }
    return r;
}

extern "C" void fn_802B9BA0(
    Body* a, OtherBody* b, void* unused, Callback* callback
) {
    record(18);

    Matrix matrix __attribute__((aligned(16)));
    RayIn tr __attribute__((aligned(16)));
    Result result;

    Shape* shape = a->shape;
    Object_vptr_0* target = b->shape;
    fn_80287600(&matrix, b->transform, a->transform);

    int count = shape->count;
    Ray* ray = shape->rays;
    tr.filter = 0;
    tr.unk = 0;
    result.fraction = lbl_805A3F80;
    result.key1 = -1;
    result.field = 0;
    result.key2 = -1;
    float zero = lbl_805A3F84;

    while (keepLooping(count--, callback)) {
        float az = ray->a.z;
        float ay = ray->a.y;
        float ax = ray->a.x;
        tr.from.x = matrix.col[3].x +
            (az * matrix.col[2].x +
             (ax * matrix.col[0].x + ay * matrix.col[1].x));
        tr.from.y = matrix.col[3].y +
            (az * matrix.col[2].y +
             (ax * matrix.col[0].y + ay * matrix.col[1].y));
        tr.from.z = matrix.col[3].z +
            (az * matrix.col[2].z +
             (ax * matrix.col[0].z + ay * matrix.col[1].z));
        tr.from.w = zero;

        float z = ray->b.z;
        float x = ray->b.x;
        float y = ray->b.y;
        tr.to.x = matrix.col[3].x +
            (z * matrix.col[2].x +
             (x * matrix.col[0].x + y * matrix.col[1].x));
        tr.to.y = matrix.col[3].y +
            (z * matrix.col[2].y +
             (x * matrix.col[0].y + y * matrix.col[1].y));
        tr.to.z = matrix.col[3].z +
            (z * matrix.col[2].z +
             (x * matrix.col[0].z + y * matrix.col[1].z));
        tr.to.w = zero;

        if ((signed char)(target->slot5(&tr, &result) >> 24)) {
            callback->slot1(a, b);
        }

        ++ray;
    }

    record(15);
}
