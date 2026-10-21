#pragma force_active on
struct FnState {
    char pad[0x10];
    int a;
    char pad2[0x8];
    int b;
};

int fn_802812D0(struct FnState *self) {
    int temp = self->b;
    if (temp >= 0) {
        self->a = temp;
        return 0;
    }
    return 1;
}
