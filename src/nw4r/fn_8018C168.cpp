#pragma force_active on
extern "C" {

struct SomeStruct {
    unsigned int field0;
    unsigned short field4;
    unsigned short field6;
};

int fn_8018C168(SomeStruct* arg0, unsigned int arg1) {
    int result = 0;
    if (arg1 == arg0->field0 && arg0->field4 == 0xfeff && arg0->field6 == 8) {
        result = 1;
    }
    return result;
}

}
