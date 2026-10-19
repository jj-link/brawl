#pragma force_active on
extern "C" {
void* fn_8007EF70(void*, int, int, int, int);

struct Ending {
    unsigned char pad[0x78];
    void* field_78;
    unsigned char pad_7c[1];
    unsigned char state;
    unsigned char pad_7e[6];
    void* field_84;
};

void fn_37_C78(Ending* self) {
    if (self->state == 1) {
        self->field_84 = fn_8007EF70(self->field_78, 0, 0, -1, -1);
    }
}
}
