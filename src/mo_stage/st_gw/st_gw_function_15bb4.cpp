#include <types.h>
#pragma force_active on

struct GroundBase {
    char pad[0x3C];
};

struct Gimmick : GroundBase {
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
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void* node(int, void*);

    char pad40[0x134];
    void* node174;
    void* node178;
    void* node17C;
    void* node180;
};

extern "C" void* setNode__9grGimmickFv(void*);
extern "C" char jumptable_63_data_5970[];

extern "C" void* fn_63_15BB4(Gimmick* self) {
    char* base = (char*)&jumptable_63_data_5970;
    void* result = setNode__9grGimmickFv(self);

    self->node174 = self->node(0, base + 0x15C);
    self->node178 = self->node(0, base + 0x16C);
    self->node17C = self->node(0, base + 0x17C);
    self->node180 = self->node(0, base + 0x18C);

    return result;
}
