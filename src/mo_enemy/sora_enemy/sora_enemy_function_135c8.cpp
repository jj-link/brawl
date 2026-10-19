#pragma force_active on
struct Result {
    char pad[12];
    float value;
};

struct Obj {
    virtual void a();
    virtual Result* f();
    virtual void b();
};

struct Holder {
    char pad[64];
    Obj* obj;
};

extern "C" float fn_41_135C8(Holder* h) {
    return h->obj->f()->value;
}
