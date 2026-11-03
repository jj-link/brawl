#pragma force_active on
extern "C" int fn_80041D64(void*, void*);

struct Class_804207E4_base { char pad[0x44]; };
class Class_804207E4 : public Class_804207E4_base {
public:
    virtual int fn_80011148(Class_804207E4*);
};

extern "C" int fn_800110CC(Class_804207E4* self, Class_804207E4* other) {
    int result = 0;
    if (fn_80041D64((char*)self + 0x2c, (char*)other + 0x2c) && self->fn_80011148(other)) {
        result = 1;
    }
    return result;
}
