#pragma force_active on
class Class_8042B6D0 {
public:
    virtual void fn_8004805C();
    virtual void fn_8004781C();
    virtual void fn_80046A28();
    virtual void fn_8004810C();
    virtual void fn_800480DC();
    virtual void fn_801AB1C4();
    virtual void fn_801B269C();
    virtual void fn_801B26E4();
    virtual void fn_801AAFDC();
    virtual void fn_801AAFE8();
    virtual void fn_801AB290();
    virtual void fn_801B2EEC(void*, void*);
    char padding[0xe0];
    void* fieldE4;
};
struct Table { void (*fn)(void*); int padding[7]; };
extern const Table lbl_804091B8;
extern "C" void fn_800FEC58(void* self_, Class_8042B6D0* obj) {
    char* self = (char*)self_;
    *(Class_8042B6D0**)self = obj;
    obj->fn_801B2EEC(obj->fieldE4, *(void**)(self + 0xfc));
    *(int*)(self + 0x110) = 0;
    const Table* table = &lbl_804091B8;
    void (*fn)(void*) = table->fn;
    if (fn)
        table->fn(self);
}