#pragma force_active on
typedef unsigned int u32;

struct Obj {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual u32 vf13(u32 arg);   // vtable slot 0x34 (after the 2-entry destructor slot)
    char pad[0xe0];
    u32 m_e4;                    // at offset 0xe4
};

struct Slot {
    Obj* obj;
    u32 unk4;                    // 8-byte slot stride
};

struct Owner {
    char pad[0x40];
    Slot* slots;                 // at offset 0x40
};

extern "C" {
u32 fn_2_85AC(Owner* self, u32 idx) {
    Obj* o = self->slots[idx].obj;
    return o->vf13(o->m_e4);
}
}
