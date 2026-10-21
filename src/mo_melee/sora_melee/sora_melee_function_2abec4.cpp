#pragma force_active on

struct FnItem {
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
    char pad0[0xC8];
    FnList first;
    char pad1[0x1170 - 0xCC];
    FnList second;
};

extern "C" bool fn_27_2ABEC4(FnOwner* self, int id) {
    for (int i = 0; i < self->first.size(); i++) {
        FnItem* item = self->first.at(i);
        if (item != 0 && id == item->id) {
            return false;
        }
    }

    for (int i = 0; i < self->second.size(); i++) {
        FnItem* item = self->second.at(i);
        if (item != 0 && id == item->id) {
            return false;
        }
    }

    return true;
}
