#pragma force_active on
typedef unsigned int u32;
struct Result { u32 x, y, z; };
struct Node { char pad[0x1c]; u32 data; };
class Array {
public:
    virtual void unused();
    virtual Node* at(int);
};
struct Owner { char pad[0x48]; Array* array; };
struct Header { u32 a, b; };
class Module : public Header {
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
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual u32 get(u32);
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual Result fetch(u32, u32);
};
struct Modules { char pad[4]; Module* module; };
struct Data { char pad[0xd8]; Modules* modules; };
struct Accessor { char pad[0x44]; Data* data; };
extern "C" u32 fn_27_6F30C(void*);

extern "C" Result fn_27_6C634(Owner* owner, int index, u32 id, u32 arg) {
    Node* node = owner->array->at(index);
    Accessor* accessor = (Accessor*)fn_27_6F30C(&node->data);
    Module* module = accessor->data->modules->module;
    u32 value = module->get(id);
    return ((Accessor*)fn_27_6F30C(&node->data))->data->modules->module->fetch(value, arg);
}
