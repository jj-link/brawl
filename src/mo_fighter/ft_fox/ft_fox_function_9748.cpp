#pragma force_active on
struct FoxWorkPrefix {
    void* vtSecondary;
    unsigned char isNull;
};

struct FoxGeneralWork : FoxWorkPrefix {
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
    virtual void clear();

    int* intWorks;
    unsigned int intWorkSize;
    float* floatWorks;
    unsigned int floatWorkSize;
    unsigned int* flagWorks;
    unsigned int flagWorkSize;
};

struct FoxWork {
    int intWorks[0x4D];
    float floatWorks[0x20];
    unsigned int flagWorks[3];
    FoxGeneralWork generalWork;
};

extern "C" FoxGeneralWork* fn_97_9248(
    FoxGeneralWork*, int*, int, float*, int, unsigned int*, int);

extern "C" FoxWork* fn_97_9748(FoxWork* work) {
    fn_97_9248(&work->generalWork, work->intWorks, 0x4D,
               work->floatWorks, 0x20, work->flagWorks, 3);
    work->generalWork.clear();
    return work;
}
