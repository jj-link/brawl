#pragma force_active on

typedef struct {
    unsigned int pad0;
    unsigned int flags;
    char pad4[0x40];
    unsigned int data;
    char pad8[0x14];
    int field60;
    int field64;
} Obj;

extern void fn_80399CB8(void *);
extern void fn_80399CC8(void *, void *, unsigned int);
extern int fn_8039DB88(int);
extern int fn_8039DBD0(int);

int fn_8039ACE4(Obj *arg0, void *arg1, unsigned int arg2, int arg3, int arg4)
{
    if ((arg0->flags & 0x100) == 0 || (arg0->flags & 0x200) != 0) {
        return -7;
    }
    if (fn_8039DB88(arg3) == 0) {
        return -3;
    }
    if (fn_8039DBD0(arg4) == 0) {
        return -3;
    }
    if (arg1 == 0) {
        fn_80399CB8(&arg0->data);
        return 0;
    }
    if (arg4 == 1 && (arg0->flags & 2)) {
        return -4;
    }
    if (arg4 == 0) {
        unsigned int count;
        char *ptr;
        char *end;
        ptr = (char *)arg1;
        end = (char *)arg1 + arg2;
        count = 0;
        while (ptr < end) {
            if (*ptr == 0x0D && ptr[1] == 0x0A) {
                count = 0;
                ptr++;
            } else {
                count++;
                if (count > 998) {
                    return -0x18;
                }
            }
            ptr++;
        }
    }
    fn_80399CC8(&arg0->data, arg1, arg2);
    arg0->field60 = arg3;
    arg0->field64 = arg4;
    return 0;
}