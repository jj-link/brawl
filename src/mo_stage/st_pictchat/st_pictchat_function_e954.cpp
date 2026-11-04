#pragma force_active on
extern "C" {
extern char lbl_73_data_5C18[];
void fn_73_2C64(void*);
}

class Class_3E50 {
public:
    virtual void fn_73_C58C();
    virtual void fn_73_B9AC();
    virtual void fn_73_B9BC();
    virtual void fn_73_A9C8();
    virtual void fn_73_A784(int, int);
    char* node;
    int flag;
};

class Class_3F48 {
public:
    virtual void fn_73_C58C();
    virtual void fn_73_B9AC();
    virtual void fn_73_B9BC();
    virtual void fn_73_AA60();
    virtual void fn_73_A784(int, int);
};

class Class_4040 {
public:
    virtual void fn_73_C58C();
    virtual void fn_73_B9AC();
    virtual void fn_73_B9BC();
    virtual void fn_73_AAF8();
    virtual void fn_73_A784(int, int);
};

class Class_4138 {
public:
    virtual void fn_73_C58C();
    virtual void fn_73_B9AC();
    virtual void fn_73_B9BC();
    virtual void fn_73_AB90();
    virtual void fn_73_A784(int, int);
};

class Class_4400 {
public:
    virtual void fn_73_C58C();
    virtual void fn_73_B9AC();
    virtual void fn_73_B9BC();
    virtual void fn_73_ACF0();
    virtual void fn_73_A784(int, int);
};

extern "C" char* fn_73_E954(char* self) {
    fn_73_2C64(self);
    Class_3E50* s = (Class_3E50*)(self + 0xd0);
    *(char**)(self + 0x3c) = lbl_73_data_5C18;
    *(int*)(self + 0x158) = 0;
    *(int*)(self + 0x15c) = 0;
    *(int*)(self + 0x160) = 0;
    *(unsigned char*)(self + 0x164) = 0;
    *(unsigned char*)(self + 0x165) = 0;
    *(unsigned char*)(self + 0x166) = 0;
    *(int*)(self + 0x168) = 0;
    if (s == 0) {
        return self;
    }
    s->flag = 1;
    s->fn_73_A784(0, 15);
    char* p = s->node;
    *(unsigned int*)(p + 4) |= 1;
    return self;
}
