#pragma force_active on
extern "C" {

typedef struct {
    char _0[8];
    unsigned a : 18;
    unsigned b : 1;
    unsigned c : 13;
} SomeStruct;

int fn_27_D1CAC(SomeStruct* self) {
    return self->b;
}

}
