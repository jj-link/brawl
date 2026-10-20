#pragma force_active on
extern "C" void fn_27_46784(unsigned int* dst, const unsigned int* src);

class IFoo {
public:
    virtual void vf0();
    virtual unsigned int* vf1(int idx);
};

struct Holder {
    char pad[4];
    short unk4;
};

extern "C" void fn_27_46DF8(Holder* h, IFoo* obj, int idx, const unsigned int* src) {
    unsigned int* dst = obj->vf1(h->unk4 + idx);
    fn_27_46784(dst, src);
}
