#include <types.h>
#pragma force_active on

class utRelocate {
public:
    utRelocate(u8* buf, u32 size);
    ~utRelocate();
    void* getPublicAddress(const char* name) const;

private:
    u32 unk[13];
};

struct NameTable {
    const char* names[13];
};

extern "C" {
extern const NameTable lbl_1_rodata_A90;
extern s32 lbl_1_data_72AC;
extern u32 lbl_1_bss_18C8[];
extern u32 lbl_1_bss_194C[];
extern const char lbl_1_data_7754[];
}

extern "C" void fn_1_271A8(u8* buf, u32 size) {
    utRelocate reloc(buf, size);
    NameTable table;
    table = lbl_1_rodata_A90;
    for (s32 i = 0; i < lbl_1_data_72AC; i++) {
        lbl_1_bss_18C8[i] = (u32)reloc.getPublicAddress(table.names[i]);
    }
    const u32* src = (const u32*)reloc.getPublicAddress(lbl_1_data_7754);
    for (s32 i = 0; i < lbl_1_data_72AC; i++) {
        lbl_1_bss_194C[i] = src[i];
    }
}
