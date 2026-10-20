#pragma force_active on
extern "C" {
typedef struct {
    void *vtable;
    char pad[4];
    int m;
} soNullable_t;

int fn_27_D0E58(soNullable_t *self) {
    return self->m >> 25;
}
}
