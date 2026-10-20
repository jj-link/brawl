#pragma force_active on
typedef unsigned int u32;

struct Result {
    u32 words[4];
};

class Object {
    unsigned char padding[0x30];

public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual Result get();
};

extern "C" Object* fn_27_36028(void*, u32, u32);

extern "C" Result fn_27_42A54(const u32* index, void* work, u32 value) {
    return fn_27_36028(work, value, *index)->get();
}
