#pragma force_active on
class Class_8028096C {
public:
    Class_8028096C(int, int, int, int);
    ~Class_8028096C();
    char data[12];
};
class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2(int, int, char*, const char*, int);
};
extern "C" {
int fn_8027CA38(void*);
int fn_8027CC24(void*);
void* fn_8027CC1C(void*);
int fn_8027C904(void*);
void fn_80280A74(Class_8028096C*, const char*);
extern char lbl_80415668[];
extern Object_vptr_0* lbl_805A0EB0;
int fn_80333774(void* obj, unsigned char* p, unsigned int type, int, int arg4) {
    int result = 0;
    switch(type) {
    case 1: case 2: case 3: case 4: case 5: case 6: case 7: case 8: case 9:
    case 10: case 11: case 12: case 13: case 14: case 15: case 16: case 17: case 18: case 24:
        result = fn_8027CA38(obj); break;
    case 20: case 21: case 29:
        result = *p;
        result *= fn_8027CC24(obj) ? fn_8027CC24(obj) : 1;
        break;
    case 28: result = *p * 2; break;
    case 22: result = 4;
    case 26: result = result + *p + 4; break;
    case 25: {
        int n = fn_8027C904(fn_8027CC1C(obj));
        result = n * (fn_8027CC24(obj) ? fn_8027CC24(obj) : 1);
        break;
    }
    case 19: result = ((int (*)(void*, unsigned char*, unsigned int))fn_80333774)(obj, p, *((unsigned char*)obj + 13)); break;
    case 27: result = *p * 2 + 4; break;
    case 23: break;
    default: {
        char buffer[512];
        char flag = 1;
        Class_8028096C tmp((int)buffer, 512, (int)&flag, arg4);
        fn_80280A74(&tmp, lbl_80415668);
        lbl_805A0EB0->slot2(3, 0x50a18b58, buffer, lbl_80415668 + 63, 187);
        break;
    }
    }
    return result;
}
}