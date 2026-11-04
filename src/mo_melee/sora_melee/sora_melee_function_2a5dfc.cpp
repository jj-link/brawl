#pragma force_active on
class FnList {
public:
    virtual void unused0();
    virtual void unused1();
    virtual int* getAt(int index);
    virtual int size();
};
struct Owner {
    char pad0[0x1040];
    unsigned char flag0;
    char pad1[0x40];
    unsigned char flag1;
    char pad2[0x46];
    FnList list;
};
extern void* g_ftManager;
extern "C" int fn_27_10C7F0(void*);
extern "C" int fn_27_10A35C(void*);
extern "C" int fn_27_2A5DFC(Owner* self, int arg) {
    if (arg != 0) {
        int i = 0;
        while (i < self->list.size()) {
            if (*self->list.getAt(i) == 0x78) return 1;
            i++;
        }
    }
    if ((int)self->flag1 > 0) return 1;
    if (fn_27_10C7F0(g_ftManager) != 0) return 1;
    if ((int)self->flag0 > 0 || fn_27_10A35C(g_ftManager) != 0) return 1;
    return 0;
}