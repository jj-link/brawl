#pragma force_active on

extern "C" {
void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
void fn_73_41D4(void*);
void fn_73_41D8(void*, float, float, float);
void* fn_73_41E8(void*);
int fn_73_39CC(void*, int);
void* fn_73_41F8(int);
void* fn_73_4274(void*, void*);
void* fn_73_4558(void*, void*);
void* fn_73_47FC(void*, void*);
void* fn_73_4AA0(void*, void*);
void* fn_73_4D44(void*, void*);
void fn_27_264D9C(void*, void*);
extern const float lbl_73_rodata_78;
extern int lbl_73_rodata_8C[];
}

extern "C" void fn_73_3FF8(void* arg0) {
    char* self = (char*)arg0;
    void* p;
    void* temp;
    float vec[3];
    struct Params {
        void* self;
        void* value;
        int reserved;
        void* vec;
        void* list;
    } params;

    fn_73_41D4(vec);
    fn_73_41D8(vec, lbl_73_rodata_78, lbl_73_rodata_78, lbl_73_rodata_78);

    temp = __nw__FUlQ25Heaps8HeapType(8, 0xF);
    p = temp;
    if (temp != 0) {
        p = fn_73_41E8(temp);
    }
    *(void**)(self + 0x284) = p;
    *(int*)p = 0;
    *(int*)(*(char**)(self + 0x284) + 4) = 0;

    int* src = lbl_73_rodata_8C;
    params.self = (void*)*src++;
    params.value = (void*)*src++;
    params.reserved = *src++;
    params.vec = (void*)*src++;
    params.list = (void*)*src++;
    params.self = self;

    int value = fn_73_39CC(self, 0);
    params.value = fn_73_41F8(value);
    params.vec = vec;
    params.list = *(void**)(self + 0x284);

    void* result = 0;
    unsigned char type = *(unsigned char*)(self + 0x160);
    switch (type) {
    case 7: {
        void* object = __nw__FUlQ25Heaps8HeapType(0x7FC, 0xF);
        if (object)
            object = fn_73_4274(object, &params);
        result = object;
        break;
    }
    case 12: {
        void* object = __nw__FUlQ25Heaps8HeapType(0x5BC, 0xF);
        if (object)
            object = fn_73_4558(object, &params);
        result = object;
        break;
    }
    case 13: {
        void* object = __nw__FUlQ25Heaps8HeapType(0x52C, 0xF);
        if (object)
            object = fn_73_47FC(object, &params);
        result = object;
        break;
    }
    case 15: {
        void* object = __nw__FUlQ25Heaps8HeapType(0x76C, 0xF);
        if (object)
            object = fn_73_4AA0(object, &params);
        result = object;
        break;
    }
    case 25: {
        void* object = __nw__FUlQ25Heaps8HeapType(0x5BC, 0xF);
        if (object)
            object = fn_73_4558(object, &params);
        result = object;
        break;
    }
    case 27: {
        void* object = __nw__FUlQ25Heaps8HeapType(0x6DC, 0xF);
        if (object)
            object = fn_73_4D44(object, &params);
        result = object;
        break;
    }
    default:
        result = 0;
        break;
    }

    fn_27_264D9C(self, result);
}
