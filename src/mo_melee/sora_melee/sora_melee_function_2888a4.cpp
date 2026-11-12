#pragma force_active on

#define V1(n) virtual void n();
#define V4(n) V1(n##a) V1(n##b) V1(n##c) V1(n##d)
#define V16(n) V4(n##a) V4(n##b) V4(n##c) V4(n##d)

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void* slot1(int);
    virtual unsigned* slot2(int);
    virtual int slot3();
    virtual int slot4(int);
    virtual void slot5(int, int);
    virtual void slot6(int, int);
    virtual void slot7();
    virtual int slot8();
    virtual int slot9(int);
    virtual int slot10();
    virtual void slot11();
    virtual void slot12(int, int, int);
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual int slot16();
    virtual int slot17(int);
    virtual void slot18(int);
    virtual void slot19(int, int);
};

class WorkFlag {
public:
    V16(a) V1(b) V1(c) V1(d)
    virtual void set(int);
};

struct Object_vptr_4_base {
    char pad[4];
};

class Object_vptr_4 : public Object_vptr_4_base {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual float slot5(void*, int, int);
    virtual int slot6(void*, int, int);
};

struct Class_90D8_base {
    char pad[8];
};

class Class_90D8 : public Class_90D8_base {
public:
    virtual void fn_27_7B274();
    virtual void fn_27_7AC18();
    virtual void fn_27_7AC28();
    virtual void fn_27_7AB50();
    virtual void fn_27_7B2EC();
    virtual void fn_27_7AB10();
    virtual void fn_27_7AD2C();
    virtual void fn_27_7AEDC();
    virtual void fn_27_7B22C();
    virtual void fn_27_7AC38();
    virtual void fn_27_7ADE8();
    virtual void fn_27_7AF98();
    virtual void fn_27_7B0B0();
    virtual void fn_27_7ABD8();
    virtual void fn_27_7ABCC(void*, int, int, int, void*);
};

struct OwnerBase {
    char pad[0x3c];
};

class Owner : public OwnerBase {
public:
    V16(a) V16(b) V4(c) V4(d) V1(e) V1(f) V1(x)
    virtual void update();
    V16(g) V16(h) V16(i) V16(j) V16(k)
    V4(l) V4(m) V1(r) V1(s) V1(t)
    virtual void setValue(int);
};

class LargeModule {
public:
    V4(a)
    virtual int enabled(int);
    V16(b) V16(c) V16(d) V16(e)
    V1(f) V1(g)
    virtual int value(int);
};

class FloatModule {
public:
    V16(a) V16(b) V4(c) V4(d)
    V1(f) V1(g) V1(h) V1(i) V1(j)
    virtual void first(float);
    V1(k)
    virtual void second(float);
    virtual void third(float);
};

struct Offset8Base {
    char pad[8];
};

class Offset8Module : public Offset8Base {
public:
    V16(a) V4(b) V4(c) V4(d) V4(e)
    V16(f) V16(g) V16(h) V16(i)
    V4(j) V4(k) V4(l) V4(m) V4(n) V4(v)
    V1(o) V1(p) V1(q) V1(r) V1(s) V1(t) V1(u)
    virtual void set(int);
};

class Offset8Reset : public Offset8Base {
public:
    V16(a) V1(b) V1(c)
    virtual void reset();
};

class Offset8Float : public Offset8Base {
public:
    V4(a) V4(b) V1(c) V1(d) V1(e)
    virtual void set(float);
};

struct AccessModules {
    char pad[0x14];
    Object_vptr_0* module;
};

struct Accesser {
    char pad[0xd8];
    AccessModules* modules;
};

struct ModuleTable {
    char pad[0x70];
    Object_vptr_0* module;
};

struct Entry {
    char pad[0x38];
    int value;
};

struct RawBss {
    int a;
    int b;
};

extern RawBss lbl_27_bss_71C8;
extern const float lbl_27_rodata_4610;
extern const float lbl_27_rodata_461C;

extern "C" void fn_27_B1D60(void*, unsigned);
extern "C" void fn_27_B1D84(void*, unsigned);
extern "C" void fn_27_8D5C8(void*, int, int);
extern "C" void fn_27_289104(void*);

inline void setPartVisibility(char* self, bool enabled)
{
    *reinterpret_cast<unsigned char*>(self + 0x3c68) = enabled;
    if (*reinterpret_cast<unsigned char*>(self + 0x3c68)) {
        if (reinterpret_cast<Object_vptr_0*>(self + 0x2aac)->slot4(0x1000000a) > 0) {
            reinterpret_cast<Object_vptr_0*>(self + 0x3a68)->slot12(2, 0, -1);
            return;
        }
    }
    reinterpret_cast<Object_vptr_0*>(self + 0x3a68)
        ->slot12(2, *reinterpret_cast<unsigned char*>(self + 0x3c68), -1);
}

inline unsigned char pickFlag(int result, int kind)
{
    unsigned char f = 0;
    if (result == kind)
        f = 2;
    return f;
}

extern "C" void fn_27_2888A4(
    void* p, int oldState, int newState, int argument, Accesser* accesser)
{
    char* self = static_cast<char*>(p);

    *reinterpret_cast<int*>(self + 0x3d38) = -1;
    Object_vptr_0* work = reinterpret_cast<Object_vptr_0*>(self + 0x2aac);
    *reinterpret_cast<int*>(self + 0x3d3c) = -1;
    *reinterpret_cast<unsigned char*>(self + 0x3d41) = 0;

    if ((*reinterpret_cast<ModuleTable**>(self + 0x1a4))->module->slot16() != 2 &&
        work->slot4(0x1000000a) > 0) {
        reinterpret_cast<Object_vptr_0*>(self + 0x19cc)->slot19(2, 0);
        if (reinterpret_cast<Object_vptr_0*>(self + 0x3ab4)->slot3() > 2) {
            reinterpret_cast<Object_vptr_0*>(self + 0x3a68)->slot12(2, 0, -1);
        }
    }

    if (work->slot17(0x12000005)) {
        accesser->modules->module->slot6(2, 0);
    }

    (*reinterpret_cast<Class_90D8**>(self + 0x8d0))
        ->fn_27_7ABCC(p, oldState, newState, argument, accesser);
    reinterpret_cast<Offset8Reset*>(self + 0x3a04)->reset();

    if (newState != oldState) {
        if (newState == 2) {
            reinterpret_cast<WorkFlag*>(work)->set(0x12000009);
            int result = reinterpret_cast<Object_vptr_4*>(&lbl_27_bss_71C8)
                             ->slot6(self + 0xcc, 0x5b70, 0);
            int mode;
            int value;
            unsigned char flag;

            switch (result) {
            case 1:
            case 3:
                mode = 0;
                value = 0;
                flag = pickFlag(result, 3);
                break;
            case 2:
            case 4:
                mode = 2;
                value = 0;
                flag = pickFlag(result, 4);
                break;
            case 0:
            default:
                mode = 1;
                value = 0;
                flag = 0;
                break;
            }

            for (int i = 0;
                 i < reinterpret_cast<Object_vptr_0*>(self + 0x284c)->slot3();
                 ++i) {
                Entry* entry = static_cast<Entry*>(
                    reinterpret_cast<Object_vptr_0*>(self + 0x284c)->slot1(i));
                entry->value = mode;
                fn_27_B1D60(
                    reinterpret_cast<Object_vptr_0*>(self + 0x284c)->slot1(i),
                    value);
                fn_27_B1D84(
                    reinterpret_cast<Object_vptr_0*>(self + 0x284c)->slot1(i),
                    flag);
            }

            for (int i = 0;
                 i < reinterpret_cast<Object_vptr_0*>(self + 0x3ab4)->slot3();
                 ++i) {
                if (i != 1) {
                    if (i == 2)
                        *reinterpret_cast<unsigned char*>(self + 0x3c68) = 1;
                    reinterpret_cast<Object_vptr_0*>(self + 0x3a68)
                        ->slot12(i, 1, -1);
                }
            }
            reinterpret_cast<Offset8Module*>(self + 0xe7c)->set(1);
        } else if (oldState == 2) {
            work->slot5(0, 0x10000017);
            *reinterpret_cast<unsigned char*>(self + 0x3c68) = 0;

            for (int i = 0;
                 i < reinterpret_cast<Object_vptr_0*>(self + 0x3ab4)->slot3();
                 ++i) {
                reinterpret_cast<Object_vptr_0*>(self + 0x3a68)
                    ->slot12(i, 0, -1);
            }
            for (int i = 0;
                 i < reinterpret_cast<Object_vptr_0*>(self + 0x284c)->slot3();
                 ++i) {
                Entry* entry = static_cast<Entry*>(
                    reinterpret_cast<Object_vptr_0*>(self + 0x284c)->slot1(i));
                entry->value = 1;
            }

            reinterpret_cast<Offset8Module*>(self + 0xe7c)->set(0);
            if (reinterpret_cast<Object_vptr_0*>(self + 0x27a8)->slot9(3)) {
                int value = reinterpret_cast<LargeModule*>(self + 0x27a8)->value(3);
                if (*reinterpret_cast<int*>(self + 0x8c0) != 0x9e)
                    reinterpret_cast<Owner*>(self)->setValue(value);
            }
            *reinterpret_cast<int*>(self + 0x2124) = 0;
            reinterpret_cast<Offset8Float*>(self + 0x3cd0)
                ->set(lbl_27_rodata_461C);
            reinterpret_cast<Owner*>(self)->update();
        }

        if (static_cast<unsigned>(oldState - 6) <= 1) {
            if (newState == 5 && oldState == 7 &&
                work->slot4(0x1000001c) > 0) {
                work->slot18(0x22000000);
                reinterpret_cast<FloatModule*>(self + 0x15c0)->first(
                    reinterpret_cast<Object_vptr_4*>(&lbl_27_bss_71C8)
                        ->slot5(self + 0xcc, 0xd6f, 0));
                reinterpret_cast<FloatModule*>(self + 0x15c0)->second(
                    reinterpret_cast<Object_vptr_4*>(&lbl_27_bss_71C8)
                        ->slot5(self + 0xcc, 0xd70, 0));
            }

            reinterpret_cast<Object_vptr_0*>(self + 0x19cc)->slot19(3, 0);
            if (reinterpret_cast<Object_vptr_0*>(self + 0x3ab4)->slot3() > 2) {
                setPartVisibility(self, false);
            }
            reinterpret_cast<Owner*>(self)->setValue(1);

            if (oldState == 7) {
                switch (*reinterpret_cast<int*>(self + 0x8c0)) {
                case 42:
                    fn_27_8D5C8(
                        self + 0xb8,
                        reinterpret_cast<Object_vptr_0*>(self + 0xf60)->slot8(),
                        0x6b);
                    break;
                case 0:
                    fn_27_8D5C8(
                        self + 0xb8,
                        reinterpret_cast<Object_vptr_0*>(self + 0xf60)->slot8(),
                        0x6c);
                    break;
                default:
                    if (*reinterpret_cast<Object_vptr_0*>(self + 0x297c)->slot2(8)
                        & 0x8000) {
                        fn_27_8D5C8(
                            self + 0xb8,
                            reinterpret_cast<Object_vptr_0*>(self + 0xf60)->slot8(),
                            0x6d);
                    }
                    break;
                }
            }
        }

        if (newState == 5) {
            work->slot5(-1, 0x1000001c);
            if (!reinterpret_cast<Object_vptr_0*>(self + 0x2aac)
                     ->slot17(0x22000000)) {
                unsigned value =
                    *reinterpret_cast<Object_vptr_0*>(self + 0x297c)->slot2(8);
                if (value & 0x10000f) {
                    reinterpret_cast<FloatModule*>(self + 0x15c0)
                        ->first(lbl_27_rodata_4610);
                    reinterpret_cast<FloatModule*>(self + 0x15c0)
                        ->second(lbl_27_rodata_4610);
                    reinterpret_cast<FloatModule*>(self + 0x15c0)
                        ->third(lbl_27_rodata_461C);
                }
            }
        }
        if (oldState == 6)
            fn_27_289104(p);
    }
}
