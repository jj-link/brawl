#pragma force_active on
extern "C" {
extern unsigned char lbl_8040ABD8[];
}

class Base {
public:
    virtual bool vf2(const void** key);
};

extern "C" Base* fn_73_41F8(Base* obj) {
    bool found = false;
    if (obj != 0) {
        const void* key = lbl_8040ABD8;
        if (obj->vf2(&key)) {
            found = true;
        }
    }
    if (found) {
        return obj;
    }
    return 0;
}
