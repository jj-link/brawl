#pragma force_active on

typedef unsigned int u32;

struct Vec3 {
    float x, y, z;
};

struct Entry {
    int id;
    Vec3 position;
    float value;
};

struct Entries {
    Entry* data;
    u32 count;
};

class Object {
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
    virtual void apply(int, int, Vec3*, Vec3*, int, int, int, float, int);

    char pad[0x5c];
    Entries* entries;
};

extern "C" const float lbl_27_rodata_C5C;

extern "C" void fn_27_99D88(Object* self, int arg1, int arg2) {
    if (self->entries) {
        for (u32 i = 0; i < self->entries->count; ++i) {
            Vec3 position;
            Vec3 zero = {
                lbl_27_rodata_C5C,
                lbl_27_rodata_C5C,
                lbl_27_rodata_C5C
            };
            Entry* entry = &self->entries->data[i];
            position.x = entry->position.x;
            position.y = entry->position.y;
            position.z = entry->position.z;
            self->apply(arg1, self->entries->data[i].id,
                        &position, &zero, 0, arg2, 0,
                        self->entries->data[i].value, -1);
        }
    }
}
