#pragma force_active on
struct StageData {
    char pad[0x184];
    unsigned char field184;
    void* field188;
    float field18c;
};

extern "C" void fn_84_3E24(StageData* self, unsigned char a, void* b, float c) {
    self->field184 = a;
    self->field188 = b;
    self->field18c = c;
}
