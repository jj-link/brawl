#pragma force_active on
typedef float f32;
typedef unsigned char u8;
typedef unsigned short u16;

struct Vec {
    float x, y, z;

    Vec() : x(lbl()), y(lbl()), z(lbl()) {}
    Vec(float a, float b, float c) : x(a), y(b), z(c) {}

    static float lbl();
};

extern const float lbl_27_rodata_3C4;
extern const float lbl_27_rodata_3C8;

inline float Vec::lbl() {
    return lbl_27_rodata_3C4;
}

struct Matrix {
    float m[3][4];

    inline Vec getPosition() const {
        return Vec(m[0][3], m[1][3], m[2][3]);
    }

    inline void setPosition(const Vec& v) {
        m[0][3] = v.x;
        m[1][3] = v.y;
        m[2][3] = v.z;
    }
};

struct Joint {
    char pad[0x50];
    u16 id;
};

struct Coll {
    char pad[6];
    u16 count;
};

struct Pad8 {
    char pad[8];
};

struct Pad3C {
    char pad[0x3C];
};

struct Node : Pad8 {
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
    virtual void getMatrix(u16, Matrix*, int);
};

struct Model : Pad3C {
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
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void update();
};

struct Inner {
    char pad[4];
    Node* node;
};

struct Outer {
    char pad[8];
    Model* model;
    char pad1[0xCC];
    Inner* inner;
};

struct Flags {
    u8 b7 : 1;
    u8 b6 : 1;
    u8 b5 : 1;
    u8 rest : 5;
};

struct Self : Pad8 {
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
    virtual float scale();

    char pad1[0x20];
    int active;
    Coll* collision;
    Matrix* matrices;
    Flags flags;
    char pad2[0x1B];
    Outer* outer;

    inline void update();
};

extern "C" {
void fn_8003E918(Matrix*, float);
Joint* getJoint__11grCollisionFUs(Coll*, unsigned int);
void mul__6MatrixCFPC6MatrixP6Matrix(const Matrix*, const Matrix*, Matrix*);
}

extern "C" void fn_27_25E18(Self* self) {
    int off;
    Node* node;
    unsigned int count;
    unsigned int i;
    Matrix rotation;

    if (!self->active || !self->collision)
        return;
    if (self->flags.b7)
        return;

    if (self->flags.b6)
        fn_8003E918(&rotation, -(lbl_27_rodata_3C8 * self->scale()));

    Outer* o = self->outer;
    node = o->inner->node;
    o->model->update();

    count = self->collision->count;
    i = 0;
    off = 0;
    for (; i < count; ++i) {
        Joint* joint = getJoint__11grCollisionFUs(self->collision, i);
        if (joint) {
            Matrix* matrix = (Matrix*)((char*)self->matrices + off);
            node->getMatrix(joint->id, matrix, 0);

            if (self->flags.b6) {
                if (self->flags.b5) {
                    mul__6MatrixCFPC6MatrixP6Matrix(matrix, &rotation, matrix);
                } else {
                    Vec pos = matrix->getPosition();
                    matrix->setPosition(Vec());
                    mul__6MatrixCFPC6MatrixP6Matrix(&rotation, matrix, matrix);
                    matrix->setPosition(pos);
                }
            }
        }
        off += 0x30;
    }
}
