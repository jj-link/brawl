#pragma force_active on
#pragma fp_contract on
struct Vec4 { float x, y, z, w; };
struct Bounds { unsigned char pad[0x40]; float v[4]; };
struct Shape { unsigned char pad[0x14]; Vec4* first; unsigned char pad2[0x0C]; Vec4* second; unsigned char pad3[0x0C]; Vec4* third; };
struct Obj { unsigned char pad[0x0C]; int a; int b; };
extern "C" void fn_80287A64(float*, float*, Shape*);
extern "C" int fn_8031FEFC(void*, Shape*, Vec4*, int*, int*);
extern "C" int fn_803201D8(void*, int, int, Vec4*);
extern "C" int fn_8031D9AC(Bounds* bounds, Obj* object, Shape* shape, Vec4* point, int* result) {
 float transformed[4] __attribute__((aligned(16)));
 float d[3][4];
 int first;
 int second;
 Vec4* p0 = shape->first;
 d[0][0] = point->x - p0->x;
 d[0][1] = point->y - p0->y;
 d[0][2] = point->z - p0->z;
 d[0][3] = point->w - p0->w;
 Vec4* p1 = shape->second;
 d[1][0] = point->x - p1->x;
 d[1][1] = point->y - p1->y;
 d[1][2] = point->z - p1->z;
 d[1][3] = point->w - p1->w;
 Vec4* p2 = shape->third;
 d[2][0] = point->x - p2->x;
 d[2][1] = point->y - p2->y;
 d[2][2] = point->z - p2->z;
 d[2][3] = point->w - p2->w;
 fn_80287A64(transformed, d[0], shape);
 if (((transformed[0] < bounds->v[0]) << 3 | (transformed[1] < bounds->v[1]) << 2 |
     (transformed[2] < bounds->v[2]) << 1 | (transformed[3] < bounds->v[3])) & 0xe) {
  *result = 0; return 1;
 }
 first = 0;
 if (fn_8031FEFC(object, shape, point, &first, &second)) { *result = 3; return 1; }
 if (0x37 - object->b + object->a < first) { *result = 2; return 1; }
 if (fn_803201D8(object, first, second, point)) { *result = 3; return 1; }
 return 0;
}