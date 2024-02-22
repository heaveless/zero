#ifndef API_H
#define API_H

#include "lua52/lua.h"
#include "lua52/lauxlib.h"
#include "lua52/lualib.h"

#define API_TYPE_FONT "Font"

char *luastart_main(const char *filename);
void api_load_libs(lua_State *L);

#endif
