#pragma force_active on
struct Matrix {
    float m[12];
};

extern "C" void setIdentity__6MatrixFv(Matrix*);
extern "C" void inverse__6MatrixCFP6Matrix(const Matrix*, Matrix*);
extern "C" void mul__6MatrixCFPC6MatrixP6Matrix(
    const Matrix*, const Matrix*, Matrix*);

struct Base {
    char pad[8];
};

struct Model : Base {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void get(int, Matrix*, int);
};

struct Modules {
    char pad[4];
    Model* model;
};

struct Access {
    char pad[0xD8];
    Modules* modules;
};

struct Object {
    char pad[0x44];
    Access* access;
    int unknown;
    int index;
    int unknown50;
    Matrix matrix;
};

extern "C" void fn_41_27A68(Object* self, int index) {
    Matrix a, b, c;
    setIdentity__6MatrixFv(&a);
    setIdentity__6MatrixFv(&b);
    setIdentity__6MatrixFv(&c);

    Model* model = self->access->modules->model;
    model->get(self->index, &b, 0);

    model = self->access->modules->model;
    model->get(index, &a, 0);

    inverse__6MatrixCFP6Matrix(&a, &c);
    setIdentity__6MatrixFv(&self->matrix);
    mul__6MatrixCFPC6MatrixP6Matrix(&c, &b, &self->matrix);
}
