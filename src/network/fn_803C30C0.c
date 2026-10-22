#pragma force_active on
typedef struct {
    void *data;
    int state;
} Request;

typedef struct {
    char pad[0x14];
    int handle;
} Object;

extern int fn_803C4DEC(void);
extern void fn_803C4158(int);
extern int fn_803C4F38(int, int, int);
extern Object *fn_803C4410(int);
extern int fn_803C2958(Request *);
extern int fn_803C2AB0(void);
extern int fn_803AE4F4(int);

int fn_803C30C0(int arg0, int arg1, int arg2)
{
    int result;
    Object *obj;
    Request request;

    result = fn_803C4DEC();
    if (result != 0) {
        fn_803C4158(result);
        return result;
    }

    result = fn_803C4F38(arg0, arg1, arg2);
    if (result != 0) {
        fn_803C4158(result);
        return result;
    }

    obj = fn_803C4410(arg0);
    if (obj == 0) {
        fn_803C4158(0xB002);
        return 0xB002;
    }

    request.data = (char *)obj + 8;
    request.state = 0;
    if (fn_803C2958(&request) != 0) {
        result = fn_803C2AB0();
        fn_803C4158(result);
        fn_803AE4F4(obj->handle);
        return result;
    }

    return 0;
}
