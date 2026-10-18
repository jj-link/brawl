#pragma force_active on
typedef unsigned char u8;
typedef unsigned long u32;

class soNodeHolder {
public:
    virtual void vf0();
    virtual soNodeHolder* getNode();
    u8 unk4[0xC];
    bool m_updateFlag;
};

class soModelModuleImpl {
public:
    void setVirtualNodeUpdate(u32 nodeId, bool flag);
    u8 unk0[0x90];
    soNodeHolder* m_holder;
};

void soModelModuleImpl::setVirtualNodeUpdate(u32 nodeId, bool flag) {
    soNodeHolder* h = m_holder->getNode();
    h->m_updateFlag = flag;
}
