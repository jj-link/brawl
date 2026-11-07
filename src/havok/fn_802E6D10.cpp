#pragma force_active on
#pragma fp_contract on
extern float lbl_805A43E0, lbl_805A43F4;
struct Vec { float x,y,z,w; } __attribute__((aligned(16)));
struct Self { char pad[8]; float value; };
struct Entry { char pad[8]; char type[8]; char data[0xac]; float a,b; char pad2[12]; Vec d,e,f; };
namespace hkMath { float max2f(float, float); }
extern "C" {
Entry* fn_802E6D08(int, int);
int fn_802E6F38(void*);
void fn_80297444(void*, const void*);
void fn_80294D1C(void*, float);
void fn_802DB598(void*);
void* fn_802DB588(void*);
void* fn_802DB624(void*);
void fn_80287A64(void*, void*, void*);
void fn_802879F8(void*, void*, void*);
void fn_802E6F40(void*, void*);
void fn_802E6F8C(void*, void*);
void fn_802E67C8(void*, void*, void*, void*);
}
extern "C" void fn_802E6D10(Self* self, void* input, int* list, int count, int offset) {
    float one = lbl_805A43F4;
    for (int i = count - 1; i >= 0; ++list, --i) {
        Entry* p = fn_802E6D08(*list, offset);
        switch (fn_802E6F38(p->type)) {
        case 7: break;
        case 8: {
            fn_80297444(&p->e, input);
            float t = self->value;
            fn_80294D1C(&p->e, hkMath::max2f(lbl_805A43E0, one - t * p->a));
            fn_80294D1C(&p->f, hkMath::max2f(lbl_805A43E0, one - t * p->b));
            Vec v40, v30, v20, v10;
            fn_802DB598(&v40);
            fn_802DB598(&v30);
            fn_80287A64(&v30, fn_802DB624(fn_802DB588(p)), &p->f);
            fn_802DB598(&v20);
            fn_802E6F40(&v20, &p->d);
            fn_802E6F8C(&v30, &v20);
            fn_802879F8(&v40, fn_802DB624(fn_802DB588(p)), &v30);
            fn_802E67C8(self, &p->e, &p->f, p->data);
            fn_802DB598(&v10);
            fn_80287A64(&v10, fn_802DB624(fn_802DB588(p)), &v40);
            fn_802E6F8C(&v10, &p->d);
            fn_802879F8(&p->f, fn_802DB624(fn_802DB588(p)), &v10);
            break;
        }
        default: {
            fn_80297444(&p->e, input);
            float t = self->value;
            fn_80294D1C(&p->e, hkMath::max2f(lbl_805A43E0, one - t * p->a));
            fn_80294D1C(&p->f, hkMath::max2f(lbl_805A43E0, one - t * p->b));
        }
        case 6:
            fn_802E67C8(self, &p->e, &p->f, p->data);
            break;
        }
    }
}