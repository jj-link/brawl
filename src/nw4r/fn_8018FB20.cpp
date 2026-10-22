#pragma force_active on
struct Obj {
    int pad0;
    int off4;
    char pad[0x42];
    short s4a;
};

struct Handle {
    void* p;

    Handle(void* v) : p(v) {}
};

struct Holder {
    Obj* p;

    Obj* get() const { return p; }
};

extern "C" int fn_8018EFFC(Handle*, int);

extern "C" int fn_8018FB20(const Holder* arg0) {
    Obj* o = arg0->get();
    if (o->s4a != -1) {
        Handle ptr(o->off4 ? (char*)o + o->off4 : 0);
        return fn_8018EFFC(&ptr, o->s4a);
    } else {
        return 0;
    }
}
