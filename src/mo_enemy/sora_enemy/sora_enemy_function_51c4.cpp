#include <em/em_info.h>
#pragma force_active on

struct V3 { float x, y, z; V3() {} V3(const V3& v) : x(v.x), y(v.y), z(v.z) {} };
struct LocalEnemy;
class Model : private soNull, public soNullable {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void set(int, V3*);
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual V3 get(int);
    virtual void v48();
    virtual void v49();
};
class LocalNullable {
public:
    virtual void isNull();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15(V3*, int);
    virtual void slot16();
    virtual int slot17(int);
    virtual void slot18();
};
class Class_6E20 {
public:
    virtual void fn_41_3516C();
    virtual void fn_41_34F30();
    virtual void fn_41_350A4();
    virtual void fn_41_350AC();
    virtual void fn_41_350B4();
    virtual void fn_41_350BC();
    virtual void fn_41_350DC();
    virtual void fn_41_350C4();
    virtual void fn_41_35120();
    virtual void fn_41_350CC();
    virtual void fn_41_350D4();
    virtual void fn_41_350E4();
    virtual void fn_41_350EC();
    virtual void fn_41_350F0();
    virtual void fn_41_350F4();
    virtual void fn_41_350F8();
    virtual void fn_41_350FC();
    virtual int fn_41_35108(int);
    virtual void fn_41_3510C();
};
struct Modules {
    char pad0[4];
    Model* model;
    char pad8[4];
    LocalNullable* other;
    char pad10[0x54];
    Class_6E20* work;
};
struct EnemyVtable {
    char pad[0x15c];
    unsigned int (*valid)(LocalEnemy*, int);
};
struct LocalEnemy {
    char pad0[0x3c];
    EnemyVtable* vtable;
    char pad40[0x6c];
    EnemyKind kind;
    char padb0[0x104];
    Modules* modules;
};
extern "C" void fn_41_6270(V3*, LocalEnemy*, int);
extern "C" void fn_41_534C(V3*, const V3*);
extern "C" void fn_41_51C4(LocalEnemy* self, int node) {
    int count = emInfo::getInstance()->getNodeNum(self->kind);
    Model* model = self->modules->model;
    LocalNullable* other = self->modules->other;
    if (node >= count) {
        for (int i = 0; i < count; i++)
            fn_41_51C4(self, i);
    } else if (reinterpret_cast<Enemy*>(self)->isSetableNode(node) == 1U) {
        V3 pos = model->get(node);
        if (node == 0) {
            other->slot15(&pos, 0);
            int value = self->modules->work->fn_41_35108(0x12000003);
            other->slot18();
            V3 tmp;
            fn_41_6270(&tmp, self, value);
            fn_41_534C(&pos, &tmp);
            model->set(0, &pos);
        } else {
            model->set(node, &pos);
            other->slot15(&pos, node);
        }
    }
}
