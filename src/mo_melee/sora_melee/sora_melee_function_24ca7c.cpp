#pragma force_active on

struct MainObj_base { char pad[0x3c]; };

class MainObj : public MainObj_base {
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
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual int v46(unsigned char* a, unsigned char* b);
    virtual int v47(unsigned char a, unsigned char b, void** c, int* d, unsigned char* e);
    virtual void v48(void* a, unsigned char b, unsigned char c, int d, int e);

    char pad_40[0x94];
    unsigned char m_d4;
    char pad_d5[0xF7];
    int m_1cc;
    int m_1d0;
    int m_1d4;
    char pad_1d8[8];
    unsigned char m_1e0;
    char pad_1e1[0xb];
    int m_1ec[7];
    int m_208[1];
};

struct OtherObj_base { char pad[0x3c]; };

class OtherObj : public OtherObj_base {
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
};

extern "C" void fn_27_24CA7C(MainObj* self, int arg2) {
    if (self->m_d4 == 0) return;
    if (self->m_1e0 == 0) return;

    void* obj;
    int index;
    unsigned char byteA;
    unsigned char byte9;
    unsigned char byte8;

    while (self->m_1e0 != 0 && self->m_1cc < self->m_1d0) {
        if (!self->v46(&byteA, &byte9)) break;
        if (!self->v47(byteA, byte9, &obj, &index, &byte8)) break;
        self->v48(obj, byteA, byte9, index, arg2);
        self->m_208[index] = self->m_1d4;
        self->m_1ec[index] = 0;
        self->m_1cc++;
        self->m_1d4++;
        if (byte8 != 0) {
            reinterpret_cast<OtherObj*>(obj)->v24();
        }
        if (arg2 == 0) break;
    }
}