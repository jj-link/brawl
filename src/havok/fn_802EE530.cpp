#pragma force_active on

struct Data {
    char pad0[8];
    void** resources;
    int resourceCount;
    int pad10;
    void** entries;
    int entryCount;
    int pad1C;
    void** others;
    int otherCount;
    int pad28;
    void* finalData;
    int finalCount;
};

extern "C" {
void fn_802ED550(void*, void*);
void fn_802ED81C(void*, void*);
void fn_802ECBC0(void*, void*);
void fn_802ECDE8(void*, void**, int);
void fn_802EE0F8(void*, void*, int);

void fn_802EE530(void* object, Data* data) {
    for (int i = 0; i < data->entryCount; i++)
        fn_802ED550(object, data->entries[i]);

    for (int i = 0; i < data->otherCount; i++)
        fn_802ED81C(object, data->others[i]);

    if (data->resourceCount < 4) {
        for (int i = 0; i < data->resourceCount; i++)
            fn_802ECBC0(object, data->resources[i]);
    } else {
        fn_802ECDE8(object, data->resources, data->resourceCount);
    }

    if (data->finalCount > 0)
        fn_802EE0F8(object, data->finalData, data->finalCount);
}
}
