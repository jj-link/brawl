#pragma force_active on

struct FnItem {
    char pad[0x8C0];
    int id;
};

class FnList {
public:
    virtual void vfunc0();
    virtual FnItem*& at(int index);
    virtual void vfunc3();
    virtual int size() const;
};

struct FnOwner {
    char pad[0x6D8];
    FnList list;
};

extern "C" FnItem* fn_27_2A8A98(FnOwner* self, int id) {
    for (int i = 0; i < self->list.size(); i++) {
        FnItem* item = self->list.at(i);
        if (item != 0 && id == item->id) {
            return item;
        }
    }
    return 0;
}
