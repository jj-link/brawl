#pragma force_active on
namespace nw4r { namespace g3d { class ScnMdl; } }
extern "C" void fn_8008E31C(void*, nw4r::g3d::ScnMdl*);
extern "C" void fn_8008E374(void*, nw4r::g3d::ScnMdl*);

class Model {
public:
    char pad[8];
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual nw4r::g3d::ScnMdl* get();
};
struct Modules { char pad[4]; Model* model; };
struct Access { char pad[0xd8]; Modules* modules; };
class Object {
public:
    char pad[8];
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual bool test1();
    virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20();
    virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24();
    virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28();
    virtual void v29(); virtual void v30(); virtual void v31(); virtual void v32();
    virtual void v33(); virtual void v34(); virtual void v35();
    virtual bool test2(); virtual bool test3();
    char pad2[0x18];
    Access* access;
    void* a;
    void* b;
};
extern "C" void fn_27_11550(Object* self) {
    if (self->a != 0 && self->test1() == true) {
        fn_8008E31C(self->a, self->access->modules->model->get());
    }
    if (self->b != 0 && (self->test2() == true || self->test3() == true)) {
        fn_8008E374(self->b, self->access->modules->model->get());
    }
}