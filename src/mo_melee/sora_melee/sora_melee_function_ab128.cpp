#pragma force_active on
typedef unsigned char u8;
typedef signed int s32;

struct ResourceArray {
    u8 mFlag : 1;
    u8 mFlags : 7;
    u8 mPad[3];
    const u8* mBegin;
    const u8* mEnd;
    void* mData;
    s32 mCount;
};

extern "C" {
extern const u8 lbl_27_data_15CB0[];

void fn_27_AB128(ResourceArray* entry) {
    entry->mFlag = true;
    entry->mBegin = lbl_27_data_15CB0;
    entry->mEnd = lbl_27_data_15CB0 + 0xC;
    entry->mData = 0;
    entry->mCount = -1;
}
}
