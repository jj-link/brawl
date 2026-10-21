#pragma force_active on
typedef struct Obj {
    int unk0;
    int unk4;
    int unk8;
} Obj;

extern "C" {
void fn_8005C2A0(int unused, Obj* arg1) {
    arg1->unk8 += 0x10000;
}
}
