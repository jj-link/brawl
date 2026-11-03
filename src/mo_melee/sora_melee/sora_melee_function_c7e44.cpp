#pragma force_active on
struct Value {
    int a, b;
    short c, d;
};
struct Node {
    Value value;
    signed char prev, next;
    char pad[6];
};
class Class_206B8 {
public:
    virtual void fn_27_C8040();
    virtual void fn_27_C7AFC();
    virtual void fn_27_C7B78();
    virtual int fn_27_C7E24();
    unsigned int flags;
    int unknown;
    Node nodes[32];
};
extern "C" void fn_27_C7E44(Class_206B8* self, int start, const Value* value, int count) {
    if (count != 0) {
        if (count + start >= self->fn_27_C7E24()) {
            count = self->fn_27_C7E24() - start;
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