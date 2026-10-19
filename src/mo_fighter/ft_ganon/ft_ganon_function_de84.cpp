#pragma force_active on
class StageObject;

class gfTask {
public:
    static void* getTask(int id);
};

class soExternalValueAccesser {
public:
    static bool getWorkFlag(StageObject* obj, unsigned long flag);
};

class WorkMod {
public:
    virtual void s2() = 0;
    virtual void s3() = 0;
    virtual void s4() = 0;
    virtual void s5() = 0;
    virtual int s6(int) = 0;
    virtual void s7() = 0;
    virtual void s8() = 0;
    virtual void s9() = 0;
    virtual void s10() = 0;
    virtual void s11() = 0;
    virtual void s12() = 0;
    virtual void s13() = 0;
    virtual void s14() = 0;
    virtual void s15() = 0;
    virtual void s16() = 0;
    virtual void s17() = 0;
    virtual void s18() = 0;
    virtual bool isFlag(unsigned long) = 0;
    virtual void setFlag(unsigned long) = 0;
};

class OtherMod {
public:
    virtual void t2() = 0;
    virtual void t3() = 0;
    virtual void t4() = 0;
    virtual void t5() = 0;
    virtual void t6() = 0;
    virtual void t7() = 0;
    virtual void t8(int, int) = 0;
};

extern char lbl_109_data_2148[];
extern char lbl_109_data_2248[];

extern "C" void* __dynamic_cast(void*, long, const void*, const void*, short);

extern "C" void fn_109_DE84(char* self) {
    WorkMod* work = *(WorkMod**)(*(char**)(self + 0xd8) + 0x64);
    void* task = gfTask::getTask(work->s6(0x20000000));
    if (task == 0) {
        return;
    }
    StageObject* obj = (StageObject*)__dynamic_cast(task, 0x3c, lbl_109_data_2148, lbl_109_data_2248, 1);
    if (!work->isFlag(0x22000012) &&
        !work->isFlag(0x22000013) &&
        soExternalValueAccesser::getWorkFlag(obj, 0x12000003)) {
        OtherMod* p = *(OtherMod**)(*(char**)(self + 0xd8) + 0x14);
        p->t8(2, 0);
        work->setFlag(0x22000012);
    }
    if (!work->isFlag(0x22000014) &&
        !work->isFlag(0x22000015) &&
        soExternalValueAccesser::getWorkFlag(obj, 0x12000004)) {
        work->setFlag(0x22000014);
    }
}
