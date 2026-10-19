#pragma force_active on
extern "C" void* getInstance__9itManagerFv();
extern "C" void* getItemFromInstanceId__9itManagerFi(void*, int);

extern "C" void* fn_27_B874C(int id) {
    return getItemFromInstanceId__9itManagerFi(getInstance__9itManagerFv(), id);
}
