#pragma force_active on
typedef unsigned char u8;

class ftManager {
public:
    int getPlayerNo(int);
};

class SecondObj {
    char padding[0x3C];
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
    virtual void v29(int);
    virtual void v30();
    virtual void v31();
    virtual void v32(int, int);
};

class SelfClass {
public:
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
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
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual int v43();

    int m_0x04;
    int m_0x08;
    u8* m_0x0C;
    int m_0x10;
    int m_0x14;
    int m_0x18;
    int m_0x1C;
    int m_0x20;
    int m_0x24;
    int m_0x28;
    SecondObj* m_0x2C;
    int m_0x30;
    u8 m_0x34;
};

extern "C" {
    extern ftManager* g_ftManager;
}

extern "C" void fn_27_27E6AC(SelfClass* self, int arg1) {
    if (self->v43() != 0 && (self->m_0x34 >> 7) & 1 && self->m_0x2C != 0) {
        int playerNo = g_ftManager->getPlayerNo(arg1);
        u8* p = self->m_0x0C + playerNo * 0x5C;
        u8 b = p[0x9A];
        self->m_0x2C->v29(b);
        self->m_0x2C->v32(b, 0);
    }
}
