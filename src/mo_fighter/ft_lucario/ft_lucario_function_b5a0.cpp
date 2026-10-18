#pragma force_active on
typedef unsigned int u32;

struct ftLucarioVirtBase {
    virtual void slot0();
    virtual void slot1();
    virtual u32 slot2();
};

extern "C" u32 fn_118_B5A0(ftLucarioVirtBase* self) {
    return reinterpret_cast<ftLucarioVirtBase*>(reinterpret_cast<char*>(self) + 0x10000 - 0x68)->slot2();
}
