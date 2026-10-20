#pragma force_active on
typedef unsigned int u32;

struct Entry {
    unsigned char pad[0x30];
    u32 ptr;
};

extern "C" Entry lbl_27_bss_3210[];

extern "C" u32 fn_27_148A9C() {
    u32 p = lbl_27_bss_3210[0].ptr;
    return *reinterpret_cast<u32*>(p + 0x90);
}
