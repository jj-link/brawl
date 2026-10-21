#pragma force_active on
#pragma scheduling off
struct Target {
    char pad[0x32];
    char unk32;
    char pad2[0x4];
    char unk37;
    char pad3[0x8];
    int unk40;
};

struct Obj {
    char pad[0x6C];
    Target* unk6C;
};

extern "C" void fn_801078D8(Obj* arg0, int arg1) {
    Target* p = arg0->unk6C;
    if (!p)
        return;
    *(char*)((char*)p + arg1 + 0x37) = 1;
    *(char*)((char*)p + arg1 + 0x32) = 0;
    p->unk40 = arg1;
}
