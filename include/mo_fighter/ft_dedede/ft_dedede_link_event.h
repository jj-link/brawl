#pragma once

struct soLinkEventArgs;
class soModuleAccesser;
class StageObject;
struct DededeLinkFighter;

extern "C" {
void fn_27_1DA618(void*, unsigned int);
void fn_27_1DB0F0(void*, soLinkEventArgs*, soModuleAccesser*, StageObject*, int);
void fn_117_1FCD0(DededeLinkFighter*, soLinkEventArgs*, soModuleAccesser*, StageObject*, int);
}
