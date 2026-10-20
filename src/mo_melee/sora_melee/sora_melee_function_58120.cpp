#pragma force_active on
extern "C" int playSE__14snd3DGeneratorF5SndIDiii(void* gen, int id, int a, int b, int c);

struct Holder {
    int m_pad;
    void* m_gen;
};

class Base {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual Holder* get();
};

extern "C" int fn_27_58120(Base* self, int, int p5, int p6, int p7) {
    Holder* h = self->get();
    if (h->m_gen != 0) {
        return playSE__14snd3DGeneratorF5SndIDiii(h->m_gen, p5, p6, 0, p7);
    }
    return -1;
}
