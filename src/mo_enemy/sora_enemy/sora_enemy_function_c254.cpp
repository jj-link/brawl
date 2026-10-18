#pragma force_active on
typedef struct Owner {
    char pad[0xC];
    int *counts;
} Owner;

extern "C" {
int fn_41_C254(Owner *self, int idx) {
    return self->counts[idx]++;
}
}
