#pragma force_active on

struct GroundBase {
    char pad[0x3C];
};

class Ground : public GroundBase {
public:
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
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void v55();
    virtual int setNodeCollision(bool, unsigned long, unsigned long, bool);

    char pad40[4];
    void** m_models;

    int setNodeCollision(bool, unsigned long, const char*, bool);
};

extern "C" void* GetResNode__Q34nw4r3g3d6ResMdlCFPCc(void*, const char*);

int Ground::setNodeCollision(bool enable, unsigned long modelIndex, const char* name, bool something) {
    void* local = 0;
    void* model = m_models[modelIndex & 0xFFFF];
    if (model == 0) return 0;
    local = *(void**)((char*)model + 0xe8);
    if (local == 0) return 0;
    char* node = (char*)GetResNode__Q34nw4r3g3d6ResMdlCFPCc(&local, name);
    if (node == 0) return 0;

    if (something) {
        int offset = *(int*)(node + 0x60);
        char* child = (offset != 0) ? node + offset : 0;
        if (child != 0) {
            setNodeCollision(enable, modelIndex,
                (unsigned long)(unsigned short)(child != 0 ? *(int*)(child + 0xc) : 0),
                something);
        }
    }

    return setNodeCollision(enable, modelIndex,
        (unsigned long)(unsigned short)(node != 0 ? *(int*)(node + 0xc) : 0),
        false);
}
