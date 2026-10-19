#pragma force_active on
typedef unsigned long u32;

extern "C" {
extern const char lbl_72_data_4290[];
}

class Ground {
public:
    void getNodeIndex(u32* out, u32 flag, const char* name);
};

class grGimmick : public Ground {
public:
    u32 setNode();
};

extern "C" u32 fn_72_C8D4(grGimmick* self) {
    u32 result = self->setNode();
    self->getNodeIndex((u32*)((char*)self + 0x15c), 0, lbl_72_data_4290);
    return result;
}
