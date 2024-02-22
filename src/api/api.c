#include "api.h"

int luaopen_system(lua_State *L);
int luaopen_renderer(lua_State *L);

char *luastart_main(const char *filename)
{
    FILE *file = fopen(filename, "r");

    fseek(file, 0, SEEK_END);
    long size = ftell(file);
    fseek(file, 0, SEEK_SET);

    char *content = (char *)malloc(size + 1);

    fread(content, 1, size, file);
    content[size] = '\0';

    fclose(file);

    return content;
}

static const luaL_Reg libs[] = {
    {"system", luaopen_system},
    {"renderer", luaopen_renderer},
    {NULL, NULL}};

void api_load_libs(lua_State *L)
{
    for (int i = 0; libs[i].name; i++)
    {
        luaL_requiref(L, libs[i].name, libs[i].func, 1);
    }
}