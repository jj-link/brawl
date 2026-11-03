#include <mt/mt_vector.h>
#pragma force_active on

struct Shape {
    Vec3f end;
    float radius;
    Vec3f contact;
    float pad1c;
    float depth;
    char pad24[0x10];
    Vec3f start;
};

extern "C" {
bool fn_27_314(const Vec3f*, const Vec3f*, const Vec3f*, const Vec3f*, float);
float fn_27_E58(Vec3f*);
void fn_27_E54(Vec3f*);
void fn_27_E7C(Vec3f*, const Vec3f*);
float fn_27_E98(const Vec3f*, const Vec3f*);
float fn_27_EC8(float);
float fn_27_1050(float);
float fn_27_FB8(const Vec3f*, const Vec3f*, const Vec3f*);
extern const float lbl_27_rodata_8[];
}

extern "C" int fn_27_744(Shape* a, Shape* b, float radius) {
    const float* k = lbl_27_rodata_8;
    float sum = radius + b->radius;
    if (!fn_27_314(&a->start, &a->end, &b->start, &b->end, sum))
        return 0;

    Vec3f diff = a->start - b->start;
    Vec3f da = a->end - a->start;
    Vec3f db = b->end - b->start;
    float dist = fn_27_E58(&diff);
    float sumSq = fn_27_1050(sum);
    float daSq = fn_27_E58(&da);
    Vec3f separation;
    fn_27_E54(&separation);
    Vec3f point;
    fn_27_E54(&point);

    if (daSq < k[1]) {
        fn_27_E7C(&separation, &(a->start - b->start));
        fn_27_E7C(&point, &a->start);
    } else {
        float t = fn_27_EC8(-fn_27_E98(&da, &diff) / daSq);
        fn_27_E7C(&point, &(a->start + t * da));
        fn_27_E7C(&separation, &(point - b->start));
    }

    float sepSq = fn_27_E58(&separation);
    if (sepSq < sumSq) {
        float len = db.length();
        float sep = mtSqrtf(sepSq);
        if (len < k[1]) {
            if (sep < k[1]) {
                fn_27_E7C(&a->contact, &b->start);
            } else if (b->radius <= radius) {
                fn_27_E7C(&a->contact, &(b->start + (b->radius / sep) * separation));
            } else {
                fn_27_E7C(&a->contact, &(point + (-radius / sep) * separation));
            }
        } else if (sep + b->radius <= radius) {
            fn_27_E7C(&a->contact, &(b->start + (b->radius / len) * db));
        } else if (sep + radius <= b->radius) {
            fn_27_E7C(&a->contact, &(point + (-radius / len) * db));
        } else {
            fn_27_E7C(&a->contact, &(b->start + k[2] * separation));
        }
        fn_27_E7C(&b->contact, &a->contact);
        a->depth = b->radius + radius - sep;
        b->depth = a->depth;
        return 1;
    }

    float dbSq = fn_27_E58(&db);
    if (dbSq < k[1])
        return 0;

    Vec3f closest;
    fn_27_E54(&closest);
    if (daSq < k[1]) {
        fn_27_E7C(&closest, &a->start);
    } else {
        float dot = fn_27_E98(&da, &db);
        daSq = daSq * dbSq - fn_27_1050(dot);
        if (daSq < k[1]) {
            float candidate = fn_27_FB8(&a->start, &a->end, &b->start);
            float t;
            if (k[3] <= candidate && candidate <= k[4]) {
                t = candidate;
            } else {
                float u = fn_27_FB8(&b->start, &b->end, &a->start);
                if (k[3] <= u && u <= k[4])
                    t = k[3];
                else if (candidate < k[3])
                    t = k[3];
                else
                    t = k[4];
            }
            fn_27_E7C(&closest, &(a->start + t * da));
            fn_27_E7C(&diff, &(closest - b->start));
            dist = fn_27_E58(&diff);
        } else {
            dot *= fn_27_E98(&diff, &db);
            float numerator = dbSq * -fn_27_E98(&diff, &da);
            numerator += dot;
            float t = numerator / daSq;
            if (t <= k[3]) {
                fn_27_E7C(&closest, &a->start);
            } else {
                if (t >= k[4])
                    fn_27_E7C(&closest, &a->end);
                else
                    fn_27_E7C(&closest, &(a->start + t * da));
                fn_27_E7C(&diff, &(closest - b->start));
                dist = fn_27_E58(&diff);
            }
        }
    }

    float dot = -fn_27_E98(&diff, &db);
    float discriminant = fn_27_1050(dot) - dbSq * (dist - sumSq);
    if (discriminant < k[3])
        return 0;

    float t = (-dot - mtSqrtf(discriminant)) / dbSq;
    if (t < k[3] || t > k[4])
        return 0;

    Vec3f hit = b->start + t * db;
    Vec3f delta = hit - closest;
    fn_27_E7C(&a->contact, &(closest + (radius / sum) * delta));
    fn_27_E7C(&b->contact, &a->contact);

    t = fn_27_FB8(&b->start, &b->end, &closest);
    if (t < k[3])
        t = k[3];
    else if (t > k[4])
        t = k[4];

    fn_27_E7C(&hit, &(b->start + t * db));
    fn_27_E7C(&delta, &(hit - closest));
    a->depth = b->radius + radius - delta.length();
    b->depth = a->depth;
    return 1;
}
