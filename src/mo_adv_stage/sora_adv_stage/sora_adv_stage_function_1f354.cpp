#pragma force_active on
// fn_40_1F354: copies one 0xA0-byte entry onto another. Both entries come from the
// virtual getEntry(int), which sits at vtable offset 0x70 (index 28).
// Type and member names are placeholders. Copy codegen constrains only sizes, offsets,
// and whether a field is float, 16-bit, 8-bit, or a 4-byte integer/pointer.
// Signedness and pointer types are not determined by the copy code.

struct AdvStageWordPair {
    unsigned int m_0x0;
    unsigned int m_0x4;
};

struct AdvStageEntry {
    float m_0x0;
    float m_0x4;
    float m_0x8;
    float m_0xc;
    AdvStageWordPair m_0x10;  // 8-byte member, copied as a unit in the original
    unsigned int m_0x18;
    unsigned int m_0x1c;
    AdvStageWordPair m_0x20;  // 8-byte member, copied as a unit in the original
    unsigned int m_0x28;
    unsigned short m_0x2c;
    unsigned short m_0x2e;
    unsigned char m_0x30;
    unsigned char m_0x31;
    unsigned char m_0x32;
    unsigned char m_0x33;
    unsigned char m_0x34;
    unsigned char m_0x35;
    unsigned char m_0x36;
    unsigned char m_0x37;
    unsigned char m_0x38;
    unsigned char m_0x39;
    unsigned char m_0x3a;
    unsigned int m_0x3c;
    AdvStageWordPair m_0x40;  // 8-byte member, copied as a unit in the original
    unsigned int m_0x48;
    float m_0x4c;
    unsigned int m_0x50;
    unsigned int m_0x54;
    unsigned int m_0x58;
    unsigned int m_0x5c;
    float m_0x60;
    float m_0x64;
    float m_0x68;
    unsigned int m_0x6c;
    unsigned int m_0x70;
    unsigned int m_0x74;
    unsigned int m_0x78;
    float m_0x7c;
    AdvStageWordPair m_0x80;  // 8-byte member, copied as a unit in the original
    unsigned int m_0x88;
    AdvStageWordPair m_0x8c;  // 8-byte member, copied as a unit in the original
    float m_0x94;
    unsigned int m_0x98;
    unsigned char m_0x9c;
};

class AdvStageEntryTable {
public:
    // vfunc0..vfunc25 are placeholders. Observed: with 28 placeholders, getEntry landed
    // at offset 0x78. With 26, it lands at 0x70, which matches the original.
    virtual void vfunc0();
    virtual void vfunc1();
    virtual void vfunc2();
    virtual void vfunc3();
    virtual void vfunc4();
    virtual void vfunc5();
    virtual void vfunc6();
    virtual void vfunc7();
    virtual void vfunc8();
    virtual void vfunc9();
    virtual void vfunc10();
    virtual void vfunc11();
    virtual void vfunc12();
    virtual void vfunc13();
    virtual void vfunc14();
    virtual void vfunc15();
    virtual void vfunc16();
    virtual void vfunc17();
    virtual void vfunc18();
    virtual void vfunc19();
    virtual void vfunc20();
    virtual void vfunc21();
    virtual void vfunc22();
    virtual void vfunc23();
    virtual void vfunc24();
    virtual void vfunc25();
    virtual AdvStageEntry* getEntry(int index);
};

extern "C" void fn_40_1F354(AdvStageEntryTable* self, int srcIndex, int dstIndex) {
    AdvStageEntry* src = self->getEntry(srcIndex);
    AdvStageEntry* dst = self->getEntry(dstIndex);
    *dst = *src;
}
