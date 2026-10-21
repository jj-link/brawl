#pragma force_active on
extern "C" {
extern void fn_803EF2AC(void* a, void* b);

struct Obj {
    char pad[0x54];
    void* field54;
    char pad2[2];
    short s5a;
    short s5c;
};

void fn_8007B058(struct Obj* self, short v) {
    self->s5a = v;
    self->s5c = 0xd3;
    fn_803EF2AC(self->field54, &self->s5a);
}
}
