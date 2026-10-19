#pragma force_active on
struct WorkHeader {
    unsigned char padding[8];
};

class DededeGeneralWork : public WorkHeader {
public:
    virtual void unused00();
    virtual void unused01();
    virtual void unused02();
    virtual void unused03();
    virtual void unused04();
    virtual void unused05();
    virtual void unused06();
    virtual void unused07();
    virtual void unused08();
    virtual void unused09();
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
    virtual void reset();
};

extern "C" DededeGeneralWork* fn_117_7980(
    DededeGeneralWork*, int*, int, float*, int, unsigned int*, int);

struct DededeWorkStorage {
    int intWorks[0x4D];
    float floatWorks[0x20];
    unsigned int flagWorks[3];
    DededeGeneralWork work;
};

extern "C" DededeWorkStorage* fn_117_7E80(DededeWorkStorage* object) {
    fn_117_7980(&object->work, object->intWorks, 0x4D,
                object->floatWorks, 0x20, object->flagWorks, 3);
    object->work.reset();
    return object;
}
