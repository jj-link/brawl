#pragma force_active on
#pragma use_lmw_stmw on

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual int slot2();
};

struct Wrapper {
    Object_vptr_0* object;
};

struct Context {
    unsigned char* data;
    char pad[8];
    signed char flag;
};

extern "C" void fn_802FEDA0(
    Wrapper* a, Wrapper* b, Context* c, int* out, int* reverse
) {
    unsigned char* data = c->data;
    int x = a->object->slot2();
    int y = b->object->slot2();
    unsigned int offset;
    int value;

    if (c->flag) {
        offset = x << 5;
        value = (data + offset)[y + 0x1294];
    } else {
        offset = x << 5;
        value = (data + offset)[y + 0xE94];
    }

    int rev = *(int*)(data + value * 0x34 + 0x16C4) == 2;
    if (value == 1) {
        rev = *(signed char*)(
            data + (data + offset + y)[0x190] * 0x14 + 0x9A0
        ) != 0;
    }

    *reverse = rev;
    if (rev) {
        if (c->flag) {
            value = (data + (y << 5))[x + 0x1294];
        } else {
            value = (data + (y << 5))[x + 0xE94];
        }
    }
    *out = value;
}
