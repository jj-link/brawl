#pragma force_active on
typedef int s32;

struct Blob {
    char pad[0x18];
    s32 field;
};

extern "C" {
void* fn_27_F83E0(Blob* p, s32 idx) {
    s32 k = p->field >> 26;
    s32 sum = k + idx;
    if (sum >= 0x16) {
        sum -= 0x16;
    }
    return (char*)p + sum * 12 + 0x1c;
}
}
