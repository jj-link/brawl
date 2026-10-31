#pragma force_active on
typedef unsigned char u8;

struct Fn27Obj {
    void* unk0;
    u8 pad4[6];
    u8 unkA;
};

extern "C" void fn_27_1D53FC(void* p);

extern "C" void fn_27_112EB0(Fn27Obj* p) {
    if (p->unkA != 1) {
        return;
    }
    fn_27_1D53FC((char*)p->unk0 + 0x9E8);
}
