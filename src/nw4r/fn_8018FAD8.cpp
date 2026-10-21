#pragma force_active on
struct Obj {
    int pad0;
    int off4;
    char pad[0x40];
    short s48;
};

struct Handle {
    void* p;

    Handle(void* v) : p(v) {}
};

struct Holder {
    Obj* p;

    Obj* get() const { return p; }
};

extern "C" int fn_8018EED0(Handle*, int);

extern "C" int fn_8018FAD8(const Holder* arg0) {
    Obj* o = arg0->get();
    Handle ptr(o->off4 ? (char*)o + o->off4 : 0);
    return fn_8018EED0(&ptr, o->s48);
}
