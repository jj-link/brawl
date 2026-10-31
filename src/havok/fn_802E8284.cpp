#pragma force_active on

extern "C" {

struct ObjA {
    char pad90[0x90];
    int field90;
    int field94;
    int field98;
};

struct ObjB {
    virtual void f0();
    virtual void f1(char* name, int count, ObjA* obj);
    virtual void f2(char* name, int size, int value, int length, int count);
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
};

extern char lbl_80413210[];
void fn_802E8D8C(ObjA* a, ObjB* b);

void fn_802E8284(ObjA* arg0, ObjB* arg1) {
    arg1->f1(lbl_80413210 + 0xF, 2, arg0);
    fn_802E8D8C(arg0, arg1);

    char* name = lbl_80413210 + 0x1B;
    if (!(arg0->field98 & 0x80000000)) {
        arg1->f2(name, 8, arg0->field90,
                 arg0->field94 * 4, arg0->field98 * 4);
    }

    arg1->f6();
}

}
