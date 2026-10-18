#pragma force_active on
extern "C" {
int fn_800B5854(void*, int, int, int, int);

struct SelCharSelf {
    char pad[0x410];
    void* member;
};

int fn_10_F4C8(SelCharSelf* self) {
    return fn_800B5854(self->member, 3, 1, 1, 0);
}
}
