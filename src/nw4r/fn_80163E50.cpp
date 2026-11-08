#pragma force_active on
typedef unsigned short u16;
struct Object_vptr_1c_base {
    char pad0[0xc];
    int state;
    int flag;
    char pad1[8];
};
class Object_vptr_1c : public Object_vptr_1c_base {
public:
    virtual void slot0();
    virtual void slot1(u16);
};
struct Owner {
    char pad0[0x24];
    char entry[8];
    u16 value;
    char pad1[0xe];
    u16 counter;
};
extern "C" u16 fn_8016F198(void*, void*, u16);
extern "C" int fn_80163E50(Owner* self) {
    Object_vptr_1c* buf[1024];
    int count = 0;
    u16 n = fn_8016F198(self->entry, buf, self->value);
    for (u16 i = 0; i < n; ++i) {
        Object_vptr_1c* node = buf[i];
        if (node->state == 1) {
            int inc;
            if (node->state != 1) {
                inc = 0;
            } else {
                u16 old = self->counter;
                self->counter = old - 1;
                node->slot1(old);
                node->state = 2;
                if (node->flag == 0)
                    node->slot0();
                inc = 1;
            }
            count += inc;
        }
    }
    return count;
}