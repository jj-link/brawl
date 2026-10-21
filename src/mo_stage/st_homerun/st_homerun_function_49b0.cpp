#pragma force_active on
#pragma opt_propagation off

typedef unsigned long u32;

struct Base {
    char pad[0x3C];
};

class grGimmick : public Base {
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
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual bool setNodeVisibility(bool, u32, u32, bool, bool);

    char pad40[0x148];
    u32 node188;
    u32 node18C;
    u32 node190;
};

extern "C" char lbl_88_data_AE8[];
extern "C" void* setNode__9grGimmickFv(grGimmick*);
extern "C" void getNodeIndex__6GroundFPUlUlPCc(
    void*, u32*, u32, const char*);

extern "C" void* fn_88_49B0(grGimmick* self) {
    char* names = lbl_88_data_AE8;
    void* result = setNode__9grGimmickFv(self);

    getNodeIndex__6GroundFPUlUlPCc(self, &self->node188, 0, names + 4);
    getNodeIndex__6GroundFPUlUlPCc(self, &self->node18C, 0, names + 12);
    getNodeIndex__6GroundFPUlUlPCc(self, &self->node190, 0, names + 20);

    self->setNodeVisibility(false, 0, self->node190, true, false);
    return result;
}
