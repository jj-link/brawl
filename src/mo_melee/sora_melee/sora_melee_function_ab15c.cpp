#pragma force_active on
typedef unsigned char u8;
typedef signed int s32;

struct ResourceArray {
    u8 mFlags;
    u8 mPad[3];
    const u8* mBegin;
    const u8* mEnd;
    void* mData;
    s32 mCount;
};

extern "C" {
extern const u8 lbl_27_data_15CB0[];

void fn_27_AB15C(void* obj, void* res);

void fn_27_AB15C(void* obj, void* res) {
    ResourceArray* entry = static_cast<ResourceArray*>(obj);
    entry->mFlags |= 0x80;
    entry->mBegin = lbl_27_data_15CB0;
    entry->mEnd = lbl_27_data_15CB0 + 0xC;
    entry->mData = res;
    entry->mCount = -1;
}
}
