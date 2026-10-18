#pragma force_active on
struct Obj { unsigned char pad[0x10]; int start; };

extern "C" float fn_111_11040(Obj* self, int unused, int index, int subindex) {
    float* values = *reinterpret_cast<float**>(
        reinterpret_cast<unsigned char*>(self) + (index - self->start) * 4 + 0x18
    );
    return values[subindex];
}
