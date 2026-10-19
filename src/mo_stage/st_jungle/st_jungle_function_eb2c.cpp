#pragma force_active on
typedef unsigned long u32;

class Ground {
public:
    void getNodeIndex(u32* out, u32 flag, const char* name);
};

class grGimmick : public Ground {
public:
    void* setNode();
};

extern char lbl_51_data_50F8[];

extern "C" void* fn_51_EB2C(grGimmick* self) {
    void* ret = self->setNode();
    self->getNodeIndex((u32*)((char*)self + 0x1c8), 0, lbl_51_data_50F8);
    return ret;
}
