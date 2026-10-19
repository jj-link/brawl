#pragma force_active on
typedef unsigned int u32;

extern "C" void fn_27_2EEC4(unsigned char* self, u32 a, u32 b);

class scSubObj {
public:
    virtual void* vf0();
    virtual void* vf1(u32 x);
};

struct scSelf {
    unsigned char pad[0x28];
    scSubObj* sub;
};

extern "C" {
void fn_27_26E20(scSelf* self, u32 a, u32 b) {
    unsigned char* p = (unsigned char*)self->sub->vf1(b);
    fn_27_2EEC4(p, a, 1);
}
}
