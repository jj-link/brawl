#pragma force_active on
typedef struct Owner {
    int a;
    int b;
    int c;
} Owner;

extern "C" char* fn_62_A634(Owner* self, int index) {
    int i = (self->c >> 30) + index;
    if (i >= 1) {
        i -= 1;
    }
    return (char*)self + i * 0x68 + 0xc;
}
