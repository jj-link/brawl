#pragma force_active on

struct Value {
    int a, b, c;
    short d, e;
};

struct Node {
    Value value;
    signed char prev;
    signed char next;
    char pad[6];
};

struct Object {
    virtual void unused0();
    virtual void unused1();
    virtual void unused2();
    virtual int size();

    unsigned int flags;
    int unknown;
    Node nodes[32];
};

extern "C" void fn_27_C8B70(Object* self, int start, const Value* value, int count) {
    if (count != 0) {
        if (count + start >= self->size()) {
            count = self->size() - start;
        }

        int index = (int)((self->flags << 5) & 0xFC000000) >> 27;
        while (count > 0) {
            if (start > 0) {
                --start;
            } else {
                --count;
                self->nodes[index].value = *value;
            }

            index = self->nodes[index].next;
            if (index < 0) break;
        }
    }
}
