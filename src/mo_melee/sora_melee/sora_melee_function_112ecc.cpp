#pragma force_active on
typedef unsigned char u8;

struct Obj {
    char* unk0;
    u8 pad[0xa - 4];
    u8 unk_a;
};

extern "C" {
void fn_27_1D5414(void* p);

void fn_27_112ECC(Obj* p) {
    if (p->unk_a == 1) {
        fn_27_1D5414((char*)p->unk0 + 0x9e8);
    }
}
}
