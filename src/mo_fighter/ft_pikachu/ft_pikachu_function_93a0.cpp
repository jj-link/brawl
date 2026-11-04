#pragma force_active on

class Class_7858 {
public:
    virtual unsigned int fn_98_10EB8();
    virtual int* fn_98_10474(int key);
    virtual void fn_98_FFDC();
    virtual void fn_98_FFD8();
    virtual void fn_98_FF94();
    virtual void fn_98_FF90();
    virtual void fn_98_FF8C();
    virtual void fn_98_FF88();
    virtual void fn_98_FF84();
    virtual void fn_98_FF7C();
    virtual void fn_98_FF78();
    virtual void fn_98_FF70();
    virtual void fn_98_FF6C();
    virtual int fn_98_FF64();
};

class Class_79E0 {
public:
    virtual unsigned int fn_98_11488();
    virtual int* fn_98_11040(int key);
    virtual void fn_98_FFDC();
    virtual void fn_98_FFD8();
    virtual void fn_98_FF94();
    virtual void fn_98_FF90();
    virtual void fn_98_11064();
    virtual void fn_98_FF88();
    virtual void fn_98_FF84();
    virtual void fn_98_FF7C();
    virtual void fn_98_FF78();
    virtual void fn_98_FF70();
    virtual void fn_98_FF6C();
    virtual int fn_98_FF64();
};

class Class_7A60 {
public:
    virtual unsigned int fn_98_11C88();
    virtual int* fn_98_11C34(int key);
    virtual void fn_98_FFDC();
    virtual void fn_98_FFD8();
    virtual void fn_98_FF94();
    virtual void fn_98_FF90();
    virtual void fn_98_FF8C();
    virtual void fn_98_FF88();
    virtual void fn_98_FF84();
    virtual void fn_98_FF7C();
    virtual void fn_98_FF78();
    virtual void fn_98_FF70();
    virtual void fn_98_FF6C();
    virtual int fn_98_FF64();
};

class Class_7B64 {
public:
    virtual unsigned int fn_98_11D08();
    virtual int* fn_98_1154C(int key);
    virtual void fn_98_FFDC();
    virtual void fn_98_FFD8();
    virtual void fn_98_FF94();
    virtual void fn_98_FF90();
    virtual void fn_98_FF8C();
    virtual void fn_98_FF88();
    virtual void fn_98_FF84();
    virtual void fn_98_FF7C();
    virtual void fn_98_FF78();
    virtual void fn_98_FF70();
    virtual void fn_98_FF6C();
    virtual int fn_98_FF64();
};

class Class_824C {
public:
    virtual unsigned int fn_98_744C();
    virtual int* fn_98_13A4C(int key);
    virtual void fn_98_14CF8();
    virtual void fn_98_14CF4();
    virtual void fn_98_14CF0();
    virtual void fn_98_14CEC();
    virtual void fn_98_14CE4();
    virtual void fn_98_14D2C();
    virtual void fn_98_14D24();
    virtual void fn_98_14D1C();
    virtual void fn_98_14D14();
    virtual void fn_98_14D0C();
    virtual void fn_98_14CA4();
    virtual int fn_98_14CD8();
};

class Class_8424 {
public:
    virtual unsigned int fn_98_744C();
    virtual int* fn_98_139F0(int key);
    virtual void fn_98_14EE4();
    virtual void fn_98_14EDC();
    virtual void fn_98_14ED4();
    virtual void fn_98_14ECC();
    virtual void fn_98_14EC4();
    virtual void fn_98_14EBC();
    virtual void fn_98_14EB4();
    virtual void fn_98_14EAC();
    virtual void fn_98_14EA4();
    virtual void fn_98_14E9C();
    virtual void fn_98_14E94();
    virtual int fn_98_14E8C();
};

struct Pair {
    int key;
    int value;
};

extern "C" Class_7858* fn_98_9364(void* self, int mode);

extern "C" void fn_98_93A0(void* self, int mode, Pair* pairs) {
    Class_7858* obj = fn_98_9364(self, mode);
    if (obj->fn_98_10EB8() != 1 && pairs != 0) {
        int i = 0;
        while (true) {
            if (i >= obj->fn_98_FF64()) break;
            Pair* p = pairs + i;
            int key = p->key;
            if (key < 0) break;
            int value = p->value;
            *obj->fn_98_10474(key) = value;
            i++;
        }
    }
}
