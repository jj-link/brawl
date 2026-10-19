#pragma force_active on
extern "C" int fn_800B61C0(void*);

struct GameOver {
    unsigned char pad[0x40];
    void* resource;
    int result;
};

extern "C" int fn_12_9B8(GameOver* self) {
    if (fn_800B61C0(self->resource)) {
        return 2;
    }
    return self->result;
}
