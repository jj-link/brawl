#pragma force_active on
extern "C" {
void* __dynamic_cast(void*, long, const void*, const void*, short);
void* getTask__6gfTaskFi(int);
void fn_106_DADC(void*, unsigned int);
extern const char lbl_106_data_28[];
extern const char lbl_106_data_18F0[];
}

#define S(n) virtual void s##n();

struct Obj70 {
    S(2) S(3) S(4) S(5) S(6) S(7) S(8) S(9)
    S(10) S(11) S(12) S(13) S(14) S(15) S(16) S(17)
    virtual int s18();
};

struct Obj64 {
    S(2) S(3) S(4) S(5)
    virtual int s6(int);
};

#undef S

struct Modules {
    char pad[0x64];
    Obj64* unk64;
    char pad2[0x8];
    Obj70* unk70;
};

struct Fighter {
    char pad[0xd8];
    Modules* modules;
};

struct Actor {
    char pad[0x60];
    Fighter* fighter;
};

extern "C" void fn_106_792C(Actor* self) {
    Fighter* f = self->fighter;
    if (f->modules->unk70->s18() == 0x120) {
        int count = f->modules->unk64->s6(0x20000016);
        if (count > 0) {
            for (int i = 0; i < count; i++) {
                int id = f->modules->unk64->s6(0x20000004 + i);
                void* task = getTask__6gfTaskFi(id);
                void* p = __dynamic_cast(task, 0x3c, lbl_106_data_28, lbl_106_data_18F0, 0);
                if (p != 0) {
                    fn_106_DADC(p, 0);
                }
            }
        }
    }
}
