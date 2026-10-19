#pragma force_active on
typedef struct Obj {
    int pad[2];
    int field8;
} Obj;

extern "C" void* fn_51_66B0(Obj* self, int index) {
    int sh = self->field8 >> 30;
    int i = sh + index;
    if (i >= 1) {
        i = i - 1;
    }
    return (char*)self + i * 0x78 + 0xc;
}
