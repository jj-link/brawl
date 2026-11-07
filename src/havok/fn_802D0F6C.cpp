#pragma force_active on

struct Query {
    float ax, ay, az, aw;
    float bx, by, bz, bw;
    int field20, field24;
    Query(const Query& q) :
        ax(q.ax), ay(q.ay), az(q.az), aw(q.aw),
        bx(q.bx), by(q.by), bz(q.bz), bw(q.bw),
        field20(q.field20), field24(q.field24) {}
};

struct Callback;
class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6(Query*, Callback*, void*, int);
};

struct Callback {
    Object_vptr_0* object;
    int zero;
    int field8;
    const Callback* parent;
};

class Class_80487490 {
public:
    virtual void fn_802D0AD4();
    virtual void fn_802D1434();
    virtual void fn_802D0BDC();
    virtual void fn_802D0BE4();
    virtual void fn_802D0D10();
    virtual void fn_802D0D80();
    virtual void fn_802D0F6C();
    char pad04[0x10];
    Object_vptr_0* object;
    char pad18[8];
    float x, y, z, w;
};

extern "C" void fn_802D0F6C(Class_80487490* self, const Query* input, const Callback* parent, void* collector) {
    __attribute__((aligned(16))) Query local = *input;
    Callback callback;
    int inherited = parent->field8;
    local.ax -= self->x;
    local.ay -= self->y;
    local.az -= self->z;
    local.aw -= self->w;
    local.bx -= self->x;
    local.by -= self->y;
    local.bz -= self->z;
    local.bw -= self->w;
    callback.parent = parent;
    callback.field8 = inherited;
    callback.object = self->object;
    callback.zero = 0;
    callback.object->slot6(&local, &callback, collector, inherited);
}
