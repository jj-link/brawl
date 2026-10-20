#pragma force_active on
extern unsigned char lbl_8040ABD8[];

class fnObj {
public:
    virtual bool vf0(const void** key);
    virtual void vf1();
};

extern "C" {
void* fn_27_26560C(fnObj* obj) {
    bool found = false;
    if (obj) {
        const void* key = lbl_8040ABD8;
        if (obj->vf0(&key)) {
            found = true;
        }
    }
    if (found) {
        return obj;
    }
    return 0;
}
}
