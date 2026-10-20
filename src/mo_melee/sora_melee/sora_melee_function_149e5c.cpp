#pragma force_active on
enum ftKind {
    ftKind_None = -1
};

class ftExtendParamAccesser {
public:
    static ftExtendParamAccesser* getAccesser(ftKind kind);
};

class Fighter {
    unsigned char padding[0x3C];

public:
    virtual void unused0();
    virtual void unused1();
    virtual void unused2();
    virtual void unused3();
    virtual void unused4();
    virtual void unused5();
    virtual void unused6();
    virtual void unused7();
    virtual void unused8();
    virtual void unused9();
    virtual void unused10();
    virtual void unused11();
    virtual void unused12();
    virtual void unused13();
    virtual void unused14();
    virtual void unused15();
    virtual void unused16();
    virtual void unused17();
    virtual void unused18();
    virtual void unused19();
    virtual void unused20();
    virtual void unused21();
    virtual void unused22();
    virtual void unused23();
    virtual void unused24();
    virtual void unused25();
    virtual void unused26();
    virtual void unused27();
    virtual void unused28();
    virtual void unused29();
    virtual void unused30();
    virtual void unused31();
    virtual void unused32();
    virtual void unused33();
    virtual void unused34();
    virtual void unused35();
    virtual void unused36();
    virtual void unused37();
    virtual void unused38();
    virtual void unused39();
    virtual ftKind getKind();
};

struct ModuleAccessor {
    unsigned char padding[8];
    Fighter* fighter;
};

extern "C" ftExtendParamAccesser* fn_27_149E5C(void*, ModuleAccessor accessor) {
    return ftExtendParamAccesser::getAccesser(accessor.fighter->getKind());
}
