#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;
typedef int s32;

class Foo {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void callTarget(s32 arg);

    u8 _pad0[0x154];
    s32 m_158;
    u8 _pad1[0x4];
    s32 m_160;
    u8 _pad2[0x1];
    signed char m_165;
};

extern "C" void fn_27_16708(Foo* self, s32 value) {
    if (value == -1) {
        if (((u32)self->m_165 & 1) == 1) {
            self->callTarget(self->m_160);
            s32 flags = (s32)self->m_165;
            flags = flags & ~1;
            self->m_165 = (signed char)flags;
        }
    }
    self->m_158 = value;
}
