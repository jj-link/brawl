#pragma force_active on

struct ObjectPrefix {
    unsigned char padding0[8];
    unsigned char active;
    unsigned char padding9[7];
};
struct Object : ObjectPrefix {
    virtual ~Object();
};

struct Class_90D8_base { char pad[0x8]; };
class Class_90D8 : public Class_90D8_base {
public:
    virtual void fn_27_7B274();
    virtual Object** fn_27_7AC18(int);
    virtual void fn_27_7AC28();
    virtual int fn_27_7AB50();
    virtual void fn_27_7B2EC();
    virtual void fn_27_7AB10();
    virtual void fn_27_7AD2C();
    virtual void fn_27_7AEDC();
    virtual void fn_27_7B22C();
    virtual void fn_27_7AC38();
    virtual void fn_27_7ADE8();
    virtual void fn_27_7AF98();
    virtual void fn_27_7B0B0(int);
};
struct Class_15DB8_base { char pad[0x10]; };
class Class_15DB8 : public Class_15DB8_base {
public:
    virtual void fn_27_AC9D8();
};
struct Class_19FD0_base { char pad[0x10]; };
class Class_19FD0 : public Class_19FD0_base {
public:
    virtual void fn_27_DCA5C();
};

struct Container {
    virtual void fn_27_7B274();
    virtual Object** fn_27_7AC18(int);
    virtual void fn_27_7AC28();
    virtual int fn_27_7AB50();
    virtual void fn_27_7B2EC();
    virtual void fn_27_7AB10();
    virtual void fn_27_7AD2C();
    virtual void fn_27_7AEDC();
    virtual void fn_27_7B22C();
    virtual void fn_27_7AC38();
    virtual void fn_27_7ADE8();
    virtual void fn_27_7AF98();
    virtual void fn_27_7B0B0(int);
};
struct Root {
    char pad[8];
    Container container;
};
extern "C" bool fn_27_2C2C18(Object*);

extern "C" void fn_27_2C1890(Root* self) {
    for (int i = 0; i < self->container.fn_27_7AB50(); ++i) {
        Object** entry = self->container.fn_27_7AC18(i);
        if (*entry != 0) {
            if (fn_27_2C2C18(*entry)) {
                delete *entry;
                self->container.fn_27_7B0B0(i);
                --i;
            } else {
                (*entry)->active = 1;
            }
        }
    }
}