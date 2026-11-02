#pragma force_active on

typedef struct Obj Obj;

typedef struct Inner {
    char pad0[4];
    int handle;
    char pad8[0x81];
    unsigned char b89;
    unsigned char b8a;
} Inner;

struct Obj {
    int field0;
    int (*cb)(int, Obj *);
    Inner *inner;
    char pad0c[0x70];
    int command;
    char pad80[0x38];
    int flag;
};

void fn_8020C450(int, void *);
extern int fn_8020CAEC(int);
extern void fn_8020CD14(void *, const void *);
extern int fn_802148C4(void *, void (*)(int, void *), void *);
extern int fn_80214994(void *, void *, void (*)(int, void *), void *);
extern int fn_802152E4(int, void (*)(int, void *), void *);

void fn_8020C450(int arg0, void *arg1) {
    Obj *obj = arg1;

    if (arg0 == 0) {
        int result = -0x75;
        Inner *inner = obj->inner;

        if (obj->command == 12)
            inner->b89 = 8;

        if (obj->command == 12 && obj->flag != 0)
            obj->command += 2;
        else
            obj->command += 1;

        if (obj->command == 11) {
            inner->b89 = 6;
            result = fn_802152E4(inner->handle, fn_8020C450, obj);
        } else if (obj->command == 12) {
            inner->b89 = 7;
            result = fn_80214994((char *)inner + 0x48, (char *)inner + 8,
                                 fn_8020C450, obj);
        } else if (obj->command == 13) {
            int data[16] = {0};

            fn_8020CD14(data, (char *)inner + 0x48);
            result = fn_802148C4(data, fn_8020C450, obj);
        } else if (obj->command == 14) {
            if (obj->flag == 0)
                inner->b89 = 9;
            inner->b8a = 4;
            obj->cb(fn_8020CAEC(arg0), obj);
            return;
        }

        if (result != 0)
            obj->cb(fn_8020CAEC(result), obj);
    } else {
        obj->cb(fn_8020CAEC(arg0), obj);
    }
}
