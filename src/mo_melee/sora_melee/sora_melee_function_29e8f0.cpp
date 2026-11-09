#pragma force_active on
extern const float lbl_27_rodata_46DC;
struct Msg { int id; unsigned char flag; };
class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void fn_27_14068();
    virtual void fn_27_140C0();
    virtual void fn_27_1412C();
    virtual void fn_27_14134();
    virtual void fn_27_14370();
    virtual void fn_27_14A28();
    virtual void fn_27_14A30();
    virtual void fn_27_14A38(unsigned int);
    virtual unsigned int fn_27_14A48(unsigned int);
    virtual unsigned int fn_27_14A68(unsigned int);
    virtual void fn_27_14AD8();
    virtual void fn_27_14A60();
    virtual void fn_27_14D08();
    virtual void fn_27_14EDC();
    virtual void fn_27_14D00();
    virtual void fn_27_14B80(unsigned int, Msg*, unsigned int);
    virtual void fn_27_14B88();
    virtual void fn_27_16A70();
    virtual void fn_27_16AB8();
    virtual void fn_27_1CBB4();
    virtual void fn_27_14A20();
    virtual void fn_27_1CBAC();
    virtual void fn_27_1CBA4();
    virtual void fn_27_14B98();
    virtual void fn_27_14B90();
    virtual void fn_27_1CB88();
    virtual void fn_27_14CF8();
    virtual void fn_27_16778();
    virtual void fn_27_1688C();
    virtual void fn_27_1C2E4();
    virtual void fn_27_1BC08();
    virtual void fn_27_1BCF0();
    virtual void fn_27_16AE0();
    virtual void fn_27_15604();
    virtual void fn_27_16CA8();
    virtual void fn_27_16CB0();
    virtual void fn_27_1CB80();
    virtual void fn_27_16CB8();
    virtual void fn_27_16CC0();
    virtual void fn_27_16E88();
    virtual void fn_27_16FB4();
    virtual void fn_27_170A8();
    virtual void fn_27_171D0();
    virtual void fn_27_1CB6C();
    virtual void fn_27_1CB38();
    virtual void fn_27_17334();
    virtual void fn_27_17374();
    virtual void fn_27_173A8();
    virtual void fn_27_17444();
    virtual void fn_27_17518();
    virtual void fn_27_1754C();
    virtual void fn_27_17584();
    virtual void fn_27_175FC();
    virtual void fn_27_17674();
    virtual void fn_27_17A9C();
    virtual void fn_27_17688();
    virtual void fn_27_17970();
    virtual void fn_27_17AD0();
    virtual void fn_27_17B18();
    virtual void fn_27_17B94();
    virtual void fn_27_17C10();
    virtual void fn_27_17C90();
    virtual void fn_27_17D0C();
    virtual void fn_27_17D88();
    virtual void fn_27_17E00();
    virtual void fn_27_17E78();
    virtual void fn_27_18170();
    virtual void fn_27_1838C();
    virtual void fn_27_18C40();
    virtual void fn_27_1858C();
    virtual void fn_27_18628();
    virtual void fn_27_18834();
    virtual void fn_27_18C58();
    virtual void fn_27_18A34();
    virtual void fn_27_18AD0();
    virtual void fn_27_1CB24();
    virtual void fn_27_1CB18();
    virtual void fn_27_1CB10();
    virtual void fn_27_1CB00();
    virtual void fn_27_18C70();
    virtual void fn_27_18D9C();
    virtual void fn_27_18F48();
    virtual void fn_27_191CC();
    virtual void fn_27_192F0();
    virtual void fn_27_1943C();
    virtual void fn_27_1B7D0();
    virtual void fn_27_1B8A0(unsigned int);
    virtual void fn_27_1B92C();
    virtual void fn_27_1BB88();
    virtual void fn_27_1CAF0();
    virtual void fn_27_1CADC();
    virtual void fn_27_1C4EC();
    virtual void fn_27_1CACC();
    virtual void fn_27_1CAC8();
    virtual void fn_27_1C5D0();
    virtual void fn_27_1CAC0();
    virtual void slot97();
    virtual void slot98();
    virtual void fn_27_1C630(unsigned int, unsigned int, unsigned int);
};
class Other {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8();
};
class Work {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void set(float, unsigned int);
    virtual void v14(); virtual void v15(); virtual void v16();
    virtual int get(unsigned int);
};
struct Modules { char pad[0x3c]; Other* other; char pad40[0x14]; Object_vptr_0* comp; char pad58[0xc]; Work* work; };
struct Accesser { char pad[0xd8]; Modules* modules; };
struct Object { char pad[0x60]; Accesser* accesser; };
extern "C" void fn_27_29E8F0(void*, Object* obj, int kind, void*, void*, Accesser* accesser) {
    if (kind == 10) {
        if (accesser->modules->comp->fn_27_14A48(4) == 1U) {
            accesser->modules->comp->fn_27_1C630(4, 4, 1);
            obj->accesser->modules->work->set(lbl_27_rodata_46DC, 0x11000003);
        }
    } else {
        if (accesser->modules->comp->fn_27_14A68(0) != 0) {
            if (obj->accesser->modules->work->get(0x12000002) == 0) {
                if (accesser->modules->comp->fn_27_14A68(0) == 1U) {
                    Msg msg;
                    msg.id = 0x34;
                    msg.flag = 0;
                    accesser->modules->comp->fn_27_14B80(0, &msg, 0);
                }
                if (accesser->modules->comp->fn_27_14A48(0) == 1U) {
                    accesser->modules->comp->fn_27_1B8A0(1);
                    accesser->modules->comp->fn_27_14A38(0);
                }
                accesser->modules->other->v8();
            }
        }
    }
}