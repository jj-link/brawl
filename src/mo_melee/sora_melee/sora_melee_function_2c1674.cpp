#pragma force_active on
struct FnArg;

extern "C" bool fn_27_2C2BD0(FnArg* arg);

class FnList {
public:
    virtual void vfunc0();
    virtual void vfunc1();
    virtual FnArg** getAt(int index);
    virtual int size();
};

struct FnOwner {
    int m_pad0;
    int m_pad1;
    FnList m_list;
};

extern "C" {
bool fn_27_2C1674(FnOwner* self) {
    int i = 0;
    while (i < self->m_list.size()) {
        FnArg* arg = *self->m_list.getAt(i);
        if (arg != 0) {
            if (!fn_27_2C2BD0(arg)) {
                return false;
            }
        }
        i++;
    }
    return true;
}
}
