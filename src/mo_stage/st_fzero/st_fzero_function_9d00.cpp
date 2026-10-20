#pragma force_active on
extern "C" {

typedef struct {
    int a;
    int b;
    int : 2;
    int c : 2;
    int : 28;
} MyStruct;

int fn_61_9D00(MyStruct *obj) {
    return obj->c;
}

}
