#pragma force_active on
extern "C" const char lbl_68_data_2E58[];

class grGimmick {
public:
    void* setNode();
};

class Ground {
public:
    void getNodeIndex(unsigned long* out, unsigned long flag, const char* name);
};

extern "C" {
void* fn_68_120B4(grGimmick* self) {
    void* ret = self->setNode();
    Ground* ground = reinterpret_cast<Ground*>(self);
    ground->getNodeIndex(reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(self) + 0x16c), 0, lbl_68_data_2E58);
    return ret;
}
}
