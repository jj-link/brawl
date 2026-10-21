#pragma force_active on
extern "C" {
extern char lbl_100_data_2098[8];
extern char lbl_100_data_20C4[8];
void* __dynamic_cast(void*, long, const void*, const void*, short);
int fn_27_14DB04(void*);
void* getManager__11soArchiveDbFUl(unsigned long);
void* getResFileFromId__16utArchiveManagerFl11ARCNodeTypeUlUlUl(void*, long, int, unsigned long, unsigned long, unsigned long);
}

class FeVirtualNode {
public:
    int pad[2];
    virtual void* slot0();
    virtual void* slot1();
    virtual void* slot2();
    virtual void* slot3();
    virtual void* getNode();
};

extern "C" void* fn_100_FE04(char* self, unsigned long flag, unsigned long arg) {
    FeVirtualNode* x = *(FeVirtualNode**)(*(char**)(self + 0xd8));
    void* obj = x->getNode();
    int resource = fn_27_14DB04(__dynamic_cast(obj, 0, lbl_100_data_2098, lbl_100_data_20C4, (short)1));
    void* mgr = getManager__11soArchiveDbFUl(0);
    return getResFileFromId__16utArchiveManagerFl11ARCNodeTypeUlUlUl(mgr, resource, 1, arg, (unsigned char)flag, -1);
}
