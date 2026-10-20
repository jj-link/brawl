#pragma force_active on
struct Inner {
    char pad[0xac];
    void* unkAC;
};

struct Outer {
    char pad[0x228];
    Inner* unk228;
};

extern Outer lbl_27_bss_3210;

extern "C" {
void* fn_27_147FC4() {
    return lbl_27_bss_3210.unk228->unkAC;
}
}
