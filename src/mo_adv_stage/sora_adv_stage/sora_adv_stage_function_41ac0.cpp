#pragma force_active on
extern "C" int fn_800B61C0(void*);
extern "C" int fn_800B6310(void*);

struct Stage {
    char pad0[0x6F8];
    int count;
    char pad6FC[0x714 - 0x6FC];
    void* resource;
    char pad718[0x968 - 0x718];
    int state;
    char pad96C[0xC2A - 0x96C];
    unsigned char flag;
};

extern "C" int fn_40_41AC0(Stage* self) {
    void* resource = self->resource;
    if (fn_800B61C0(resource) && fn_800B6310(resource)) {
        if (self->count <= 1 || self->flag) {
            return 2;
        }
        return 1;
    }
    return self->state;
}
