#pragma force_active on
extern "C" void fn_80135910(void* p);

struct Payload {
    int m0;
    void* m4;
};

struct Provider {
    virtual void v0();
    virtual Payload* v1();
};

struct Owner {
    char pad[0x28];
    Provider* m28;
};

extern "C" void fn_27_273F8(Owner* self) {
    fn_80135910(self->m28->v1()->m4);
}
