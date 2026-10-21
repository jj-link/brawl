#pragma force_active on
#pragma fp_contract on

extern float lbl_805A3F18;

struct Vec3 {
    float x, y, z;
};

struct Result {
    float x, y, z;
    union {
        float w;
        unsigned int id;
    };
} __attribute__((aligned(16)));

struct Shape {
    virtual void pad0();
    virtual void pad1();
    virtual void pad2();
    virtual void pad3();
    virtual void pad4();
    virtual void pad5();
    virtual void pad6();
    virtual void pad7();
    virtual void pad8();
    virtual void pad9();
    virtual void support(const Vec3*, Result*);
};

struct Entry {
    Shape* shape;
    unsigned int pad;
};

struct Container {
    char pad[0x10];
    Entry* entries;
    int count;
};

extern "C" void fn_802AEE5C(Container* self, const Vec3* direction, Result* output) {
    float best = lbl_805A3F18;
    int offset;
    int bestIndex = 0;
    int i = 0;
    offset = 0;

    for (; i < self->count; ++i, offset += 8) {
        Result value;
        Shape* shape = ((Entry*)((char*)self->entries + offset))->shape;
        shape->support(direction, &value);

        float dot = value.z * direction->z +
                    (value.x * direction->x + value.y * direction->y);
        if (dot > best) {
            output->x = value.x;
            output->y = value.y;
            output->z = value.z;
            output->w = value.w;
            best = dot;
            bestIndex = i;
        }
    }

    output->id += bestIndex << 8;
}
