#pragma force_active on
struct GameWatchGeneralWork {
    void* vtSecondary;
    unsigned char isNull;

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

struct GameWatchWork {
    int intWorks[0x4D];
    float floatWorks[0x20];
    unsigned int flagWorks[3];
    GameWatchGeneralWork generalWork;
};

extern "C" GameWatchGeneralWork* fn_107_9904(
    GameWatchGeneralWork*, int*, int, float*, int, unsigned int*, int);

extern "C" GameWatchWork* fn_107_9E04(GameWatchWork* work) {
    fn_107_9904(&work->generalWork, work->intWorks, 0x4D,
               work->floatWorks, 0x20, work->flagWorks, 3);
    work->generalWork.initialize();
    return work;
}
