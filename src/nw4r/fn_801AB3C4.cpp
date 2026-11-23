#pragma force_active on
class Self;
class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1(int, Self*, int, void*);
    virtual void slot2(int, Self*, int, void*);
    virtual void slot3(int, Self*, int, void*);
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
};
class Self {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10(void*, int*);
    void* field4;
    char pad08[0x34];
    char matrix1[0x30];
    char matrix2[0x68];
    Object_vptr_0* callback;
    unsigned char flags;
    char padD9;
    unsigned short mask;
};
inline void call1(Self* self, int phase, int value, void* arg) {
    Object_vptr_0* cb = self->callback;
    if (cb && (self->mask & 1) && (self->flags & phase))
        cb->slot1(phase, self, value, arg);
}
inline void call2(Self* self, int phase, int value, void* arg) {
    Object_vptr_0* cb = self->callback;
    if (cb && (self->mask & 2) && (self->flags & phase))
        cb->slot2(phase, self, value, arg);
}
inline void call3(Self* self, int phase, int value, void* arg) {
    Object_vptr_0* cb = self->callback;
    if (cb && (self->mask & 4) && (self->flags & phase))
        cb->slot3(phase, self, value, arg);
}
extern "C" void fn_801EC1B8(void*, void*, void*);
extern "C" void fn_801AB3C4(Self* self, int type, int value, void* arg) {
    switch (type) {
    case 1:
        call1(self, 1, value, arg);
        self->slot10(arg, &value);
        call1(self, 2, value, arg);
        call1(self, 4, value, arg);
        break;
    case 2:
        call2(self, 1, value, arg);
        call2(self, 4, value, arg);
        break;
    case 4:
        call3(self, 1, value, arg);
        fn_801EC1B8(arg, self->matrix1, self->matrix2);
        call3(self, 2, value, arg);
        call3(self, 4, value, arg);
        break;
    case 3:
    case 5:
    case 6:
    case 7:
    case 8:
    case 0x10001:
    case 0x10004:
        break;
    case 0x10003:
        self->field4 = 0;
        break;
    case 0x10002:
        self->field4 = arg;
        break;
    }
}