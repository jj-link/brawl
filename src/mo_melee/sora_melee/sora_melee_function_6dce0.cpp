#pragma force_active on
struct Result { unsigned int d[3]; };
struct Object { virtual void unused(); virtual char* get(unsigned int); };
struct Module {
    char pad[8];
    virtual void u0(); virtual void u1(); virtual void u2(); virtual void u3(); virtual void u4();
    virtual void u5(); virtual void u6(); virtual void u7(); virtual void u8(); virtual void u9();
    virtual void u10(); virtual void u11(); virtual void u12(); virtual void u13(); virtual void u14();
    virtual void u15(); virtual void u16(); virtual void u17(); virtual void u18(); virtual void u19();
    virtual void u20(); virtual void u21(); virtual void u22(); virtual void u23(); virtual void u24();
    virtual void u25(); virtual void u26(); virtual void u27(); virtual void u28(); virtual void u29();
    virtual void u30(); virtual void u31(); virtual void u32(); virtual void u33(); virtual void u34();
    virtual void u35();
    virtual Result get(unsigned int, int);
};
struct ModuleHolder { char pad[4]; Module* module; };
struct Data { char pad[0xD8]; ModuleHolder* holder; };
struct Accessor { char pad[0x44]; Data* data; };
struct Context { char pad0[0x38]; unsigned int index; char pad1[0xC]; Object* object; char pad2[4]; unsigned int value; };
extern "C" Accessor* fn_27_6F30C(void*);
extern "C" Result fn_27_6DCE0(Context* context) {
    char* node = context->object->get(context->index);
    Data* data = fn_27_6F30C(node + 0x1C)->data;
    return data->holder->module->get(context->value, 0);
}
