#pragma force_active on

struct Pair {
    int a;
    float b;
};

class Object {
public:
    virtual void unused0();
    virtual void unused1();
    virtual void unused2();
    virtual int size();

    unsigned int flags;
};

extern "C" void fn_27_9F778(Object* self, int start, const Pair* value, int count) {
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
                *(Pair*)((char*)self + index * 16 + 0xc) = *value;
            }

            index = *(signed char*)((char*)self + index * 16 + 0x15);
            if (index < 0) {
                break;
            }
        }
    }
}
