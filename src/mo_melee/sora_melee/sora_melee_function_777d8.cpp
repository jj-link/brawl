#pragma force_active on

extern "C" char lbl_27_data_1F88[];

struct Handle {
    int* ptr;
    bool invalid;

    Handle(int* p) : ptr(p), invalid(false) {}

    int value() const {
        return invalid == 1 ? -1 : *ptr;
    }
};

inline int getType(Handle h) {
    return h.value();
}

struct Value {
    int value;

    void assign(const Value& other) {
        if (this != &other)
            value = other.value;
    }
};

struct Object {
    virtual void unused0();
    virtual void unused1();
    virtual int* getValue(int);

    Value value;
    int count;
    void* data;

    void assign(const Object& other) {
        if (this != &other) {
            value.assign(other.value);
            count = other.count;
            data = other.data;
            if (count == 0)
                data = 0;
        }
    }
};

typedef int* (*GetValue)(Object*, int);

extern "C" Object* fn_27_777D8(Object* self, Object* other) {
    self->value.value = 0;
    *(void**)self = lbl_27_data_1F88;
    self->count = 0;
    self->data = 0;

    if (getType(Handle(other->getValue(0))) != 6)
        return self;

    if (self != other)
        self->assign(*other);

    return self;
}
