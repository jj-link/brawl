#pragma force_active on
typedef unsigned int u32;

namespace {
    struct WordBits {
        u32 mPad0 : 8;
        u32 mBits : 4;
        u32 mPad12 : 20;
    };

    struct WordHolder {
        u32 mWord0;
        u32 mWord4;
        WordBits mWord8;
    };
}

extern "C" void fn_27_19FF4C(WordHolder* p, u32 v) {
    p->mWord8.mBits = v;
}
