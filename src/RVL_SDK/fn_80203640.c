#pragma force_active on
struct Unknown {
    char pad[0x40];
    int a;
    int b;
    int c;
};

int fn_80203640(struct Unknown* self) {
    int sum = self->a + self->b;
    sum += self->c;
    return sum << 7;
}
