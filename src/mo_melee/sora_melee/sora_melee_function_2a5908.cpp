#pragma force_active on
extern "C" int fn_27_2B23F8(void*);

class FnList {
public:
    virtual void vf0();
    virtual void** getAt(int index);
    virtual void vf2();
    virtual int size();
};

struct FnOwner {
    char _00[0xC8];
    FnList list;
    char _cc[0x14AC - 0xCC];
    unsigned char flag;
};

extern "C" int fn_27_2A5908(FnOwner* self) {
    if (self->flag != 0) {
        return 1;
    }
    self->flag = 0;
    int i = 0;
    while (i < self->list.size()) {
        void** p = self->list.getAt(i);
        if (*p == 0 || fn_27_2B23F8(*p) == 0) {
            return 0;
        }
        i++;
    }
    self->flag = 1;
    return 1;
}
