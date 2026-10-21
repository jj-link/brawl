#pragma force_active on
typedef struct {
    int pad[3];
    int field;
} Struct_803786FC;

extern unsigned int fn_8035D728(void);
extern void fn_803785E0(void);
extern int fn_8035B2D0(int, void *, int *);

int fn_803786FC(Struct_803786FC *arg0) {
    int sp8;
    
    sp8 = fn_8035D728();
    return fn_8035B2D0(arg0->field, &fn_803785E0, &sp8) == 0;
}
