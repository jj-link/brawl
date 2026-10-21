#pragma force_active on

class Interface {
public:
    virtual char* f0();
    virtual char* f1();
    virtual char* f2();
    virtual char* f3();
};

extern "C" char* fn_80198988(char* arg0) {
    Interface* obj = (Interface*)arg0;
    return obj->f3() + 4;
}
