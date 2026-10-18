#pragma force_active on
extern "C" {
int fn_800B5854(void*, int, int, int, int);
}

struct fn_10_F344_Self {
    char pad[0x3c4];
    void* field_3c4;
};

extern "C" {
int fn_10_F344(fn_10_F344_Self* self) {
    return fn_800B5854(self->field_3c4, 3, 0x11, 1, 0);
}
}
