#pragma force_active on
typedef unsigned int u32;

struct MuMenuLike {
    unsigned char pad[0x40];
    u32 field_40;
    unsigned char pad44[4];
    void* msg;
    unsigned char pad4C[0x34];
    void* field_80;
};

extern "C" void printIndex__5MuMsgFUlUlPv(void*, u32, u32, void*);

extern "C" void fn_2_35F7C(MuMenuLike* self, u32 index, int doPrint, void* data) {
    if (doPrint) {
        printIndex__5MuMsgFUlUlPv(self->msg, 0, index, data);
    }
    self->field_40 = index;
    self->field_80 = data;
}
