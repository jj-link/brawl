#pragma force_active on
struct Node {
    virtual void unused0();
    virtual char* get();
};

struct Module {
    virtual void u00(); virtual void u01(); virtual void u02(); virtual void u03();
    virtual void u04(); virtual void u05(); virtual void u06(); virtual void u07();
    virtual void u08(); virtual void u09(); virtual void u10(); virtual void u11();
    virtual void u12(); virtual void u13(); virtual void u14(); virtual void u15();
    virtual void u16(); virtual void u17();
    virtual void invoke();
};

struct Modules { char pad[0xAC]; Module* module; };
struct Data { char pad[0xD8]; Modules* modules; };
struct Accessor { char pad[0x44]; Data* data; };
struct Object { char pad[0x48]; Node* node; };

extern "C" Accessor* fn_27_6F30C(void*);

extern "C" void fn_27_6C42C(Object* __restrict object) {
    char* result = object->node->get();
    fn_27_6F30C(result + 0x1C)->data->modules->module->invoke();
}
