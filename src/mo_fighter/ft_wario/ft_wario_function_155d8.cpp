#pragma force_active on
extern "C" {
extern unsigned char lbl_110_data_80F0[];

struct MemberStorage {
    void* vtable;
};

void fn_110_155D8(MemberStorage* object) {
    object->vtable = lbl_110_data_80F0;
}
}
