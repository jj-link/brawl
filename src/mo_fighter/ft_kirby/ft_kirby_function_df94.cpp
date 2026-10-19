#pragma force_active on
typedef unsigned char u8;

struct VirtualObject {
    virtual void v0() = 0;
    virtual void v1() = 0;
    virtual void v2() = 0;
    virtual void v3() = 0;
    virtual void v4() = 0;
    virtual void v5() = 0;
    virtual void v6() = 0;
    virtual void v7() = 0;
    virtual void v8() = 0;
    virtual void v9() = 0;
    virtual void v10() = 0;
    virtual void v11() = 0;
    virtual void v12() = 0;
    virtual void action(int, int, int) = 0;
};

extern "C" void fn_27_135DE8(void*);

extern "C" bool fn_96_DF94(void* self) {
    u8* bytes = reinterpret_cast<u8*>(self);

    if (bytes[0x1B68C] == 1) {
        return true;
    }

    if (bytes[0x1B68D] == 1) {
        void* object = *reinterpret_cast<void**>(bytes + 0x60);
        object = *reinterpret_cast<void**>(reinterpret_cast<u8*>(object) + 0xD8);
        object = *reinterpret_cast<void**>(reinterpret_cast<u8*>(object) + 0x28);
        reinterpret_cast<VirtualObject*>(object)->action(0, 0, 2);
    }

    fn_27_135DE8(self);
}
