#pragma force_active on

struct Value {
    unsigned int x, y, z;
};

class Array {
public:
    virtual ~Array();
    virtual const Value& at(int index) const = 0;
};

struct Object {
    unsigned int unknown;
    Array* array;
};

class Inner {
public:
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
    virtual Object* getObject(int index);
    virtual void v21();
    virtual int getIndex();
};

struct Self {
    char pad[0x20];
    Inner* inner;
};

extern "C" void fn_27_7022C(unsigned int value, Value* out, int a, float f);
extern "C" void fn_27_71948(Value* result, const Object* object, int index);

extern "C" void fn_27_71B1C(Self* self, int unused, int a, int b, float f) {
    Value sp14;
    Value sp8;
    Object* obj;
    int idx = self->inner->getIndex();
    if (idx < 0) {
        obj = 0;
    } else {
        obj = self->inner->getObject(idx);
    }
    if (obj != 0) {
        if (b < 0) {
            sp14.x = 0;
            sp14.y = 0;
            sp14.z = 0;
            fn_27_7022C(obj->unknown, &sp14, a, f);
        } else {
            fn_27_71948(&sp8, obj, b);
            fn_27_7022C(obj->unknown, &sp8, a, f);
        }
    }
}
