#pragma force_active on
extern "C" int fn_8018E374(void*);

struct Obj {
    char pad[0x1DC];
    int field;
};

extern "C" int fn_74_A18(Obj* self) {
    if (self->field) {
        if (fn_8018E374(&self->field))
            return 1;
    }
    return 0;
}