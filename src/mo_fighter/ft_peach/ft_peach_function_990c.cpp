#pragma force_active on
typedef unsigned int u32;

class Ft990CObj {
public:
    virtual void s08(); virtual void s0C();
    virtual void s10(); virtual void s14();
    virtual u32 getId(u32 id);
    virtual void s1C(); virtual void s20(); virtual void s24(); virtual void s28(); virtual void s2C();
    virtual void s30(); virtual void s34(); virtual void s38(); virtual void s3C(); virtual void s40();
    virtual void s44(); virtual void s48(); virtual void s4C(); virtual void s50(); virtual void s54();
    virtual void s58(); virtual void s5C(); virtual void s60(); virtual void s64(); virtual void s68();
    virtual void s6C(); virtual void s70(); virtual void s74(); virtual void s78(); virtual void s7C();
    virtual void s80(); virtual void s84();
    virtual void call(u32 id, int flag);
};

extern "C" {
extern char lbl_103_data_28[];
extern char lbl_103_data_23A0[];
void* getInstance__15gfTaskSchedulerFv();
void* getTaskById__15gfTaskSchedulerFQ26gfTask8CategoryUl(void* scheduler, int category, u32 id);
void* __dynamic_cast(void*, long, const void*, const void*, short);
void fn_103_10EF0(void* self, unsigned int mode);

void fn_103_990C(char* self) {
    Ft990CObj* work;
    u32 id;
    void* task;
    void* obj;
    Ft990CObj* st;

    work = *(Ft990CObj**)(*(char**)(*(char**)(self + 0x60) + 0xd8) + 0x64);
    id = work->getId(0x10000041);
    if (id != 0) {
        task = getTaskById__15gfTaskSchedulerFQ26gfTask8CategoryUl(getInstance__15gfTaskSchedulerFv(), 0x12, id);
        obj = __dynamic_cast(task, 0x3c, lbl_103_data_28, lbl_103_data_23A0, 0);
        if (obj != 0) {
            fn_103_10EF0(obj, 1);
        }
    }
    work = *(Ft990CObj**)(*(char**)(*(char**)(self + 0x60) + 0xd8) + 0x64);
    u32 id2 = work->getId(0x10000042);
    if (id2 != 0) {
        st = *(Ft990CObj**)(*(char**)(*(char**)(self + 0x60) + 0xd8) + 0x88);
        st->call(id2, 1);
    }
}
}
