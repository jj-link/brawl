#pragma force_active on
struct soScnMdl;

class soModelModuleImpl {
public:
    char m_pad0[0x0c];
    soScnMdl* m_scnMdl0c;
    char m_pad1[0xb4 - 0x10];
    soScnMdl* m_scnMdlB4;

    soScnMdl* getScnMdl(bool flag) const;
};

soScnMdl* soModelModuleImpl::getScnMdl(bool flag) const {
    if (flag == false) {
        return m_scnMdl0c;
    }
    return m_scnMdlB4;
}
