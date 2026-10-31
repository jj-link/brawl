#pragma force_active on

struct Fn27Count {
    char pad[4];
    int count;
};

class Fn27Object {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2(int a, int b);
    char pad[0x1C];
    Fn27Count* m_count;
    const signed char* m_data;
    char pad2[4];
    unsigned char m_active;
};

extern "C" void fn_27_5B5AC(Fn27Object* self) {
    if (self->m_active == 1) {
        int offset;
        int index;
        index = 0;
        offset = 0;
        while (index < self->m_count->count) {
            self->v2(index, self->m_data[offset]);
            offset += 3;
            index += 1;
        }
        self->m_active = 0;
    }
}
