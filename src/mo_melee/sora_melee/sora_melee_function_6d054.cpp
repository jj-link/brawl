#pragma force_active on
struct Object {
    virtual void unused();
    virtual void* get();
};

struct Context {
    char padding[0x48];
    Object* object;
};

struct Module {
    virtual void g0(); virtual void g1(); virtual void g2(); virtual void g3();
    virtual void g4(); virtual void g5(); virtual void g6(); virtual void g7();
    virtual void g8(); virtual void g9(); virtual void g10(); virtual void g11();
    virtual void call();
};

struct Modules { char padding[0xC8]; Module* module; };
struct Data { char padding[0xD8]; Modules* modules; };
struct Accessor { char padding[0x44]; Data* data; };

extern "C" Accessor* fn_27_6F30C(void*);

extern "C" void fn_27_6D054(Context self) {
    void* result = self.object->get();
    Accessor* accessor = fn_27_6F30C(static_cast<char*>(result) + 0x1C);
    accessor->data->modules->module->call();
}
