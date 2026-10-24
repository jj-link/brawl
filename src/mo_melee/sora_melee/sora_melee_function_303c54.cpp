#pragma force_active on

extern "C" {
int fn_27_8CC10(void*);
void fn_27_1DB0F0(void*, void*, void*, void*, int);
}

struct Obj54 {
    virtual void n2();
    virtual void n3();
    virtual void n4();
    virtual void n5();
    virtual void n6();
    virtual void n7();
    virtual void n8();
    virtual void n9();
    virtual void n10();
    virtual int n11(int);
    virtual void n12();
    virtual void n13();
    virtual void n14();
    virtual void n15();
    virtual void n16();
    virtual void n17();
    virtual void n18();
    virtual void n19();
    virtual void n20();
    virtual void n21();
    virtual void n22();
    virtual void n23();
    virtual void n24();
    virtual void n25();
    virtual void n26();
    virtual void n27();
    virtual void n28();
    virtual void n29();
    virtual void n30();
    virtual void n31();
    virtual void n32();
    virtual void n33();
    virtual void n34();
    virtual void n35();
    virtual void n36();
    virtual void n37();
    virtual void n38();
    virtual void n39();
    virtual void n40();
    virtual void n41();
    virtual void n42();
    virtual void n43();
    virtual unsigned int n44(int);
};

struct Obj64 {
    virtual void n02();
    virtual void n03();
    virtual void n04();
    virtual void n05();
    virtual void n06();
    virtual void n07(int, int);
};

struct Mod {
    char pad[0x54];
    Obj54* obj54;
    char pad2[0xc];
    Obj64* obj64;
};

struct Mid {
    char pad[0xd8];
    Mod* mod;
};

struct Self {
    char pad[0x60];
    Mid* acc;
};

struct OtherBase {
    char pad[0x28];
    unsigned int unk28;
    char pad2[0x10];
};

struct Other : OtherBase {
    virtual void n2();
    virtual void n3();
    virtual void n4();
    virtual void n5();
    virtual void n6();
    virtual void n7();
    virtual void n8();
    virtual void n9();
    virtual void n10();
    virtual void n11();
    virtual void n12();
    virtual void n13();
    virtual void n14();
    virtual void n15();
    virtual void n16();
    virtual void n17();
    virtual void n18();
    virtual void n19();
    virtual void n20();
    virtual void n21();
    virtual void n22();
    virtual void n23();
    virtual void n24();
    virtual void n25();
    virtual void n26();
    virtual void n27();
    virtual void n28();
    virtual void n29();
    virtual void n30();
    virtual void n31();
    virtual void n32();
    virtual void n33();
    virtual void n34();
    virtual void n35();
    virtual void n36();
    virtual void n37();
    virtual void n38();
    virtual void n39();
    virtual void n40();
    virtual int query();
    virtual int kind();
};

extern "C" void fn_27_303C54(
    Self* arg0, int* arg1, void* arg2, Other* arg3, int arg4)
{
    Obj54* obj54 = arg0->acc->mod->obj54;
    if (arg3->query() == 0 &&
        arg3->kind() == 0x18 &&
        obj54->n11(3) != 0)
    {
        unsigned int unk28 = arg3->unk28;
        unsigned int result = obj54->n44(3);
        if (result == unk28) {
            switch (*arg1) {
            case 0x455:
                int var = -1;
                switch (fn_27_8CC10(arg3)) {
                case 0x1D5:
                    var = 6;
                    break;
                case 0x1D6:
                    var = 7;
                    break;
                case 0x1DC:
                    var = 8;
                    break;
                case 0x1DD:
                    var = 9;
                    break;
                }
                arg0->acc->mod->obj64->n07(var, 0x10000005);
                break;
            }
        }
    }
    fn_27_1DB0F0(arg0, arg1, arg2, arg3, arg4);
}
