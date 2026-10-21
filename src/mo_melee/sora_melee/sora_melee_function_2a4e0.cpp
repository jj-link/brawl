#pragma force_active on
typedef unsigned int u32;

extern "C" void fn_80134CA0(void* p);
extern "C" u32 fn_80134344(void* p, u32 idx);
extern "C" void fn_27_2EE20(void* p);

struct Inner {
    void* unk0;
    void* data;
};

class Provider {
public:
    virtual void v0();
    virtual Inner* get(void* arg);
};

struct Owner {
    char pad[0x28];
    Provider* provider;
};

extern "C" {
void fn_27_2A4E0(Owner* self, void* arg) {
    fn_80134CA0(self->provider->get(arg)->data);
    if (fn_80134344(self->provider->get(arg)->data, 3) == 1) {
        fn_27_2EE20(self->provider->get(arg));
    }
}
}
