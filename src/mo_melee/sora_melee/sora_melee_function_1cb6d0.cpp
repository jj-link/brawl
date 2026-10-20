#pragma force_active on
typedef struct Obj {
    unsigned char pad[0x18];
    int f18;
} Obj;

extern "C" void* fn_27_1CB6D0(Obj* self, int idx) {
    int s = self->f18 >> 28;
    int n = s + idx;
    if (n >= 4) {
        n -= 4;
    }
    return (char*)self + 0x1c + n * 12;
}
