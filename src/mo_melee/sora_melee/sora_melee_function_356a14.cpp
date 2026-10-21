#include <types.h>
#pragma force_active on

extern unsigned char lbl_27_bss_7B0C[];
extern "C" s32 fn_27_30FACC(void*, u32, s32, void*, u32);

class Kind {
    char pad[0x3c];

public:
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
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual s32 getKind();
};

class Action {
public:
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
    virtual void set(s32, s32, s32);
};

class Work {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void set(s32, u32);
};

class Status {
public:
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
    virtual s32 get();
};

extern "C" void fn_27_356A14(void* unused, char* self) {
    Kind* kind = *(Kind**)(self + 8);
    s32 value = (kind->getKind() == 5) + 9;
    Action* action = *(Action**)(*(char**)(self + 0xd8) + 0x90);
    action->set(value, 1, -1);

    u32 base = 0x20000000;
    Work* work = *(Work**)(*(char**)(self + 0xd8) + 0x64);
    work->set(value, base + 6);

    Status* status = *(Status**)(*(char**)(self + 0xd8) + 0x70);
    if (fn_27_30FACC(lbl_27_bss_7B0C, 0, status->get(), self, 1) == 0x112) {
        Work* work2 = *(Work**)(*(char**)(self + 0xd8) + 0x64);
        work2->set(-1, base + 7);
    }
}
