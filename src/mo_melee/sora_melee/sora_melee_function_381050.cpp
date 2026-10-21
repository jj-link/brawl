#pragma force_active on
typedef unsigned int u32;

class Obj {
public:
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual Obj* get10();
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
    virtual void v25();
    virtual Obj* get26(u32);
};

struct Inner {
    char pad[0xD8];
    Obj* unkD8;
};

struct Outer {
    char pad[0x60];
    Inner* inner;
};

extern "C" void* getInstance__15gfTaskSchedulerFv();
extern "C" void* getTaskById__15gfTaskSchedulerFQ26gfTask8CategoryUl(void*, int, u32);
extern "C" void* __dynamic_cast(void*, long, const void*, const void*, short);
extern "C" u32 __RTTI__6gfTask[];
extern const char lbl_27_data_248[];
extern "C" int fn_27_8CE54(void*, u32, u32, float, float);
extern float lbl_27_rodata_7C1C;
extern float lbl_27_rodata_7C08;

extern "C" int fn_27_381050(Outer self, u32 a, u32 b) {
    Inner* in = self.inner;
    Obj* obj = *(Obj**)((char*)in->unkD8 + 0x84);
    Obj* r = obj->get26(0);
    if (r != 0) {
        void* task = r->get10();
        void* t = getTaskById__15gfTaskSchedulerFQ26gfTask8CategoryUl(
            getInstance__15gfTaskSchedulerFv(), 0xC, (u32)task);
        if (t != 0) {
            void* d = __dynamic_cast(
                t, 0x3C, lbl_27_data_248, __RTTI__6gfTask, 1);
            return fn_27_8CE54(
                d, a, b, lbl_27_rodata_7C1C, lbl_27_rodata_7C08);
        }
    }
    return 0;
}
