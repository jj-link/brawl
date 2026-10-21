#pragma force_active on
typedef unsigned short u16;

typedef struct {
    int state;
    int unk4;
    unsigned char *data;
    u16 capacity;
    u16 count;
} Buffer;

extern int fn_803CD270(void);
extern void fn_803D5064(void *, void *);
extern int fn_803D521C(void *);
extern void fn_803D4FC4(void *, void *);
extern int fn_803D5B90(void *);
extern void *memcpy(void *, const void *, unsigned long);

int fn_803D59C0(Buffer *arg0, void *arg1)
{
    struct {
        unsigned char header[0x18];
        unsigned char details[0x28];
        unsigned char name[0x4A];
    } local;
    u16 count;

    if (arg0 == 0) return 15;
    if (arg1 == 0) return 15;
    if (fn_803CD270() == 0) return 1;

    fn_803D5064(arg1, local.header);
    if (arg0->state != 4) return 1;
    if (fn_803D521C(local.details) == 0) return 7;

    fn_803D4FC4(arg1, local.name);
    if (fn_803D5B90(local.name) == 0) return 7;

    count = arg0->count;
    if (count >= arg0->capacity) return 9;

    memcpy(arg0->data + (count << 6), local.header, 0x40);
    arg0->count++;
    return 0;
}
