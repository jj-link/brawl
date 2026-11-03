#pragma force_active on
class Class_8042B6D0 {
public:
    virtual void fn_8004805C();
    virtual void fn_8004781C(int, int, int);
};
struct Self;
struct Other { int state(Self*); };
struct Inner { char pad[0x70]; int value; bool flag() { if (this == 0) return false; return value == 1; } };
struct Self {
    char pad0[0x18];
    Class_8042B6D0* obj;
    char pad1[0x28];
    void* a44;
    char pad2[4];
    char* entries[7];
    char pad3[8];
    Inner* a70;
    void* a74;
    void* a78;
    char pad4[0x10];
    Other* a8c;
    char pad5[4];
    void* a94;
    char pad6[0x11];
    unsigned char a9;
    char pad7[2];
    int ac;
    bool flag() {
        if (!a9) return false;
        return a70->flag();
    }
};
inline int Other::state(Self* self) { if (this == 0) return 0; return self->ac; }
extern "C" {
void fn_800DE360(void*);
void fn_800E244C(void*);
void fn_800E4ED0(char**, int);
void fn_800FEFF4(void*);
void fn_80105558(void*);
void fn_80108E5C(void*);
void fn_800F0F84(void*);
int fn_800FBFDC(void*);
void fn_800DC824(Self* self) {
    if (!self->flag()) {
        fn_800DE360(self->a44);
        Self* cursor = self;
        for (int i = 0; i < 7; ++i, cursor = (Self*)((char*)cursor + 4)) {
            if (cursor->entries[0]) fn_800E244C(cursor->entries[0]);
        }
        fn_800E4ED0(self->entries, 7);
    }
    if (self->a74) fn_800FEFF4(self->a74);
    if (self->a78) fn_80105558(self->a78);
    if (self->a94) fn_80108E5C(self->a94);
    if (self->a9) fn_800F0F84(self->a70);
    if (self->a8c->state(self) == 1) {
        switch (fn_800FBFDC(self->a8c)) {
        case 0:
        case 2: self->ac = 0; break;
        case 3: self->ac = 2; break;
        case 4: self->ac = 3; break;
        }
    }
    if (self->obj) self->obj->fn_8004781C(8, 0, 0);
}
}