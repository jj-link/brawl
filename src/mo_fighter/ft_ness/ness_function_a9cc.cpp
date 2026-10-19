#pragma force_active on
extern "C" void fn_101_A4CC(void*, void*, int, void*, int, void*, int);

class NessWork {
    unsigned char padding[8];

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
    virtual void initialize();
};

extern "C" void* fn_101_A9CC(unsigned char* object) {
    fn_101_A4CC(object + 0x1C0, object, 0x4D, object + 0x134,
                0x20, object + 0x1B4, 3);
    reinterpret_cast<NessWork*>(object + 0x1C0)->initialize();
    return object;
}
