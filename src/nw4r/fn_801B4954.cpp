#pragma force_active on

class Obj {
public:
    virtual void v0();
    virtual void v1();
    virtual void invoke();
    char pad[0x14];
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
};

extern "C" {
void* fn_8018ECCC(void*, const char*);
extern char lbl_8059E940;
extern char lbl_8059E948;

void fn_801B4954(Obj* self, unsigned int* arg) {
    if (*arg != self->unk18) {
        self->unk1C = (unsigned int)(*arg != 0 ? fn_8018ECCC(arg, &lbl_8059E948) : 0);
        self->unk20 = (unsigned int)(*arg != 0 ? fn_8018ECCC(arg, &lbl_8059E940) : 0);
        self->unk18 = *arg;
        self->invoke();
    }
}
}
