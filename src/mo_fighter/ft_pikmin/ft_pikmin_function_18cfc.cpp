#pragma force_active on
class Class_7D6C {
public:
    virtual void fn_113_80F4();
    virtual void fn_113_15588();
    virtual void fn_113_1BDC0();
    virtual void fn_113_1BDBC();
    virtual void fn_113_1BDB8();
    virtual void fn_113_1BDB4();
    virtual void fn_113_1BDAC();
    virtual void fn_113_1BDF4();
    virtual void fn_113_1BDEC();
    virtual void fn_113_1BDE4();
    virtual void fn_113_1BDDC();
    virtual void fn_113_1BDD4();
    virtual void fn_113_1BD6C();
    virtual void fn_113_1BDA0();
    virtual void fn_113_1BD94();
    virtual void fn_113_1BD8C();
    virtual int fn_113_1BD80();
};
class Class_7FE8 {
public:
    virtual void fn_113_80F4();
    virtual void fn_113_1552C();
    virtual void fn_113_1C084();
    virtual void fn_113_1C07C();
    virtual void fn_113_1C074();
    virtual void fn_113_1C06C();
    virtual void fn_113_1C064();
    virtual void fn_113_1C05C();
    virtual void fn_113_1C054();
    virtual void fn_113_1C04C();
    virtual void fn_113_1C044();
    virtual void fn_113_1C03C();
    virtual void fn_113_1C034();
    virtual void fn_113_1C02C();
    virtual void fn_113_1BFDC();
    virtual void fn_113_1C024();
    virtual int fn_113_1C014();
};
extern "C" unsigned int fn_113_18F1C(void*);
extern "C" int fn_113_18CFC(void* a) {
    Class_7D6C* status = *(Class_7D6C**)((char*)*(void**)((char*)*(void**)((char*)a + 0x60) + 0xd8) + 0x70);
    int kind = status->fn_113_1BD80();
    bool flag;
    switch (kind) {
    case 0x1e:
    case 0x1f:
    case 0x2c:
        flag = true;
        break;
    default:
        flag = false;
        break;
    }
    if (flag == 1) return 0;
    switch (kind) {
    case 0x19:
    case 0x1a:
        return 0;
    }
    if (fn_113_18F1C(a) == 1) return 1;
    status = *(Class_7D6C**)((char*)*(void**)((char*)*(void**)((char*)a + 0x60) + 0xd8) + 0x70);
    switch (status->fn_113_1BD80()) {
    case 0x17:
        return 1;
    }
    return 0;
}