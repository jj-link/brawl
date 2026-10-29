#pragma force_active on

struct GroundBase {
    char pad[0x3C];
};

class Ground : public GroundBase {
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
    virtual int v52(bool, unsigned long, unsigned long, bool, bool);

    char pad40[4];
    void** m_models;

    int setNodeVisibility(bool, unsigned long, const char*, bool, bool);
};

extern "C" void* GetResNode__Q34nw4r3g3d6ResMdlCFPCc(void* self, const char* name);

int Ground::setNodeVisibility(bool arg0, unsigned long index, const char* name, bool arg3, bool arg4) {
    void* local = 0;
    void* model = m_models[index];
    if (model == 0) {
        return 0;
    }
    local = *(void**)((char*)model + 0xe8);
    if (local == 0) {
        return 0;
    }
    void* node = GetResNode__Q34nw4r3g3d6ResMdlCFPCc(&local, name);
    if (node == 0) {
        return 0;
    }
    unsigned long nodeId;
    if (node != 0) {
        nodeId = *(unsigned long*)((char*)node + 0xc);
    } else {
        nodeId = 0;
    }
    return v52(arg0, index, nodeId, arg3, arg4);
}
