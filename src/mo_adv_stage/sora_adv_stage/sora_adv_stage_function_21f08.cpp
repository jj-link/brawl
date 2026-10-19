#pragma force_active on
struct grBase {
    virtual void unk0();
    virtual void unk1();
    virtual void unk2();
    virtual int unk3();
};

extern "C" bool fn_40_21F08(grBase* obj) {
    return !obj->unk3();
}
