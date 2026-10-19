#pragma force_active on
struct Vec3 {
    float x, y, z;
};

class QueryModule {
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
    virtual int isActive(int);
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
    virtual void unused40();
    virtual void unused41();
    virtual void unused42();
    virtual Vec3 getValue(int);
};

class ValueModule {
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
    virtual void setValue(float);
};

struct Modules {
    char pad0[8];
    ValueModule* value;
    char padC[0x48];
    QueryModule* query;
};

struct Accesser {
    char pad0[0xd8];
    Modules* modules;
};

extern "C" const float lbl_110_rodata_28[];

extern "C" void fn_110_DB2C(void*, Accesser* accesser) {
    const float* constants = lbl_110_rodata_28;
    ValueModule* value = accesser->modules->value;
    QueryModule* query = accesser->modules->query;

    if (query->isActive(6)) {
        const Vec3& result = query->getValue(6);
        float amount = constants[0] - result.x;

        if (amount < constants[1])
            amount = constants[1];
        else if (amount > constants[2])
            amount = constants[2];

        value->setValue(amount);
    }
}
