#pragma force_active on

class Interface {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual char* f3();
};

extern "C" char* fn_80199278(char* arg0) {
    return (char*)((Interface*)arg0)->f3() + 4;
}
