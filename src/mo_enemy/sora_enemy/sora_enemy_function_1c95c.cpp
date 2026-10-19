#pragma force_active on
extern "C" {
void fn_41_1BEA8(void*);
float fn_41_10830(void*);
void fn_41_1EF60(void*, float);

struct Thing {
    char pad[8];
    int unk8;
    char pad2[0xB4 - 0xC];
    char unkB4;
};

void fn_41_1C95C(Thing* self, void* arg, float param) {
    self->unk8 = 0;
    fn_41_1BEA8(&self->unkB4);
    *(float*)((char*)self + 0x4C) = fn_41_10830(arg);
    fn_41_1EF60(self, param);
}
}
