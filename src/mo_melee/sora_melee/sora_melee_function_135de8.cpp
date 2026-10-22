#include <types.h>
#pragma force_active on

class ClassA {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5(int, int, int, int);
};

class ClassB {
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
    virtual void v34(int);
};

class ClassC {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5(int, int, void*);
};

extern "C" s32 fn_27_135DE8(void* self) {
    u32 flag = *(u8*)((char*)self + 0x138);
    if (((flag >> 6) & 1) == 1) {
        ClassA* obj = *(ClassA**)(*(char**)(*(char**)((char*)self + 0x60) + 0xd8) + 0x50);
        obj->v5(0x1f67, 0, 0, 0);
    } else if (((flag >> 5) & 1) == 1) {
        ClassB* obj = *(ClassB**)(*(char**)(*(char**)((char*)self + 0x60) + 0xd8) + 0x28);
        obj->v34(1);
        ClassC* obj2 = *(ClassC**)(*(char**)(*(char**)((char*)self + 0x60) + 0xd8) + 0x64);
        obj2->v5(1, 0x1000003a, *(void**)((char*)self + 0x60));
    }
    return 0;
}
