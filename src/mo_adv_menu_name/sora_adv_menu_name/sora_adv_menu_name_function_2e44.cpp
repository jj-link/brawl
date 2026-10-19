#pragma force_active on
struct Fn28State {
    char pad_000[0x44];
    int field_44;
    char pad_048[0x0C];
    int field_54;
    char pad_058[0x04];
    int field_5C;
    char pad_060[0xD0];
    void* object_130;
    void* object_134;
    char pad_138[0x04];
    void* object_13C;
    char pad_140[0x28];
    void* result_168;
    char pad_16C[0x168];
    int state_2D4;
};

extern "C" {
void fn_28_175C(void*, int, void*);
void changeNodeAnimNIf__8MuObjectFPCc(void*, const char*);
void changeVisAnimNIf__8MuObjectFPCc(void*, const char*);
void setFrameVisible__8MuObjectFf(void*, float);
int fn_800B61C0(void*);
void setFrameNode__8MuObjectFf(void*, float);
extern const char lbl_28_data_18C[];
extern const float lbl_28_rodata_94;
extern const float lbl_28_rodata_8C;
}

extern "C" int fn_28_2E44(Fn28State* self) {
    void* object_130 = self->object_130;
    void* object_134 = self->object_134;
    void* object_13C = self->object_13C;
    fn_28_175C(self, 1, object_13C);

    if (self->state_2D4 == 1) {
        self->state_2D4 = 2;
        if (self->field_54 == 2) {
            changeNodeAnimNIf__8MuObjectFPCc(object_134, lbl_28_data_18C);
            changeVisAnimNIf__8MuObjectFPCc(object_134, lbl_28_data_18C);
            setFrameVisible__8MuObjectFf(object_130, lbl_28_rodata_94);
        }
    }

    if (self->state_2D4 == 2 && fn_800B61C0(object_134)) {
        self->state_2D4 = 3;
        if (self->field_54 == 2) {
            if (self->field_5C == 0) {
                self->field_44 = 2;
            } else if (self->field_5C == 2) {
                self->field_44 = 3;
            }
            setFrameNode__8MuObjectFf(object_130, lbl_28_rodata_8C);
        }
    }

    return (int)self->result_168;
}
