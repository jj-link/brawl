#pragma force_active on
extern int fn_80398680(void);
extern int fn_80398FF4(void *);
extern int fn_80399074(void *, int *);

struct Object {
    char padding[0x24];
    int value;
};

extern int fn_8039C984(int, struct Object **);
extern int lbl_805A1188[2];
extern int lbl_8059FCF0;

static inline int cleanup(void)
{
    struct Object *object;
    int value;
    int result;

    if (lbl_805A1188[0] == 0)
        return 0;

    if (--lbl_805A1188[0] > 0)
        return 0;

    result = fn_8039C984(lbl_805A1188[1], &object);
    if (result != 0)
        return result;

    result = fn_80399074(&lbl_8059FCF0, &value);
    if (result != 0)
        return result;

    object->value = value;
    return fn_80398FF4(&lbl_8059FCF0);
}

int fn_8039BA88(void)
{
    int first = fn_80398680();
    int result = cleanup();

    if (first != 0 && result != 0)
        return result;

    return first;
}
