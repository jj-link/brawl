#pragma force_active on

struct Rec;
extern "C" void fn_27_77588(Rec*, const Rec*);

struct Rec {
    unsigned char base[8];
    int field8;
    short fieldC;
    short fieldE;
    Rec& operator=(const Rec& value) {
        fn_27_77588(this, &value);
        field8 = value.field8;
        fieldC = value.fieldC;
        fieldE = value.fieldE;
        return *this;
    }
};

class Array {
public:
    virtual void slot0();
    virtual Rec& at(int);
    virtual void slot2();
    virtual int size();
};

extern "C" void fn_27_DE660(Array* self, int start, const Rec* value, unsigned int countArg) {
    int count = static_cast<int>(countArg);
    if (count + start >= self->size())
        count = self->size() - start;
    for (int i = 0; i < count; ++i)
        self->at(start + i) = *value;
}
