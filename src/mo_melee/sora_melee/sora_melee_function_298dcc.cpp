#pragma force_active on

class Work {
public:
    virtual void slot08();
    virtual void slot0C();
    virtual void slot10();
    virtual void slot14();
    virtual int getInt(unsigned int index);
    virtual void setInt(int value, unsigned int index);
};

struct Modules {
    unsigned char padding[0x64];
    Work* work;
};

struct Accessor {
    unsigned char padding[0xD8];
    Modules* modules;
};

struct Context {
    unsigned char padding[0x60];
    Accessor* accessor;
};

extern "C" int fn_27_28CCF0(void*, int);

extern "C" int fn_27_298DCC(void*, Context* context, int amount) {
    Work* work = context->accessor->modules->work;
    int value = work->getInt(0x10000000);

    if (value > 0) {
        int index;
        if (amount <= fn_27_28CCF0(context, 0x69AB)) {
            index = 0;
        } else if (amount <= fn_27_28CCF0(context, 0x69AC) * 8) {
            index = amount / fn_27_28CCF0(context, 0x69AC) + 1;
        } else {
            index = 9;
        }

        if (index >= 0 && index <= 9) {
            value -= fn_27_28CCF0(context, index + 0x69AD);
            if (value < 0) {
                value = 0;
            }
            work->setInt(value, 0x10000000);
        }
    }

    return value;
}
