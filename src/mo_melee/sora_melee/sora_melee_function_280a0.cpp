#pragma force_active on
class Inner {
public:
    virtual void unused();
    virtual struct Node* get(int arg);
};

struct Node {
    int unk0;
    void* unk4;
    char pad[0x34 - 8];
    unsigned char unk34;
};

struct Owner {
    char pad[0x28];
    Inner* inner;
};

extern "C" unsigned char fn_80136160(void* p, int n);

extern "C" unsigned char fn_27_280A0(Owner* self, unsigned int flags, int arg) {
    if (flags == 8) {
        return self->inner->get(arg)->unk34;
    }
    int mode;
    if (flags & 1) {
        mode = 0;
    } else if (flags & 8) {
        mode = 3;
    } else if (flags & 2) {
        mode = 1;
    } else {
        mode = 0;
        if (flags & 4) {
            mode = 2;
        }
    }
    return fn_80136160(self->inner->get(arg)->unk4, mode);
}
