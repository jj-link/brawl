#pragma force_active on
extern "C" {
extern char lbl_40_data_3AD8[];
void __dt__9grGimmickFv(void* self, int flag);
void __dl__FPv(void* p);

struct GimmickPart {
    virtual void vf0(int);
    virtual void vf1();
    virtual void vf2();
};

struct GimmickHolder {
    char pad[0x150];
    GimmickPart* parts[4];
};

void* fn_40_197FC(void* self, int flag) {
    if (self != 0) {
        GimmickHolder* h = (GimmickHolder*)self;
        *(char**)((char*)self + 0x3C) = lbl_40_data_3AD8;
        for (unsigned int i = 0; i < 4; i++) {
            if (h->parts[i] != 0) {
                if (h->parts[i] != 0) {
                    h->parts[i]->vf0(1);
                }
                h->parts[i] = 0;
            }
        }
        __dt__9grGimmickFv(self, 0);
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
}
