/*
 * Race Capture Pro Firmware
 *
 * Copyright (C) 2015 Autosport Labs
 *
 * This file is part of the Race Capture Pro fimrware suite
 *
 * This is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This software is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 *
 * See the GNU General Public License for more details. You should
 * have received a copy of the GNU General Public License along with
 * this code. If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef LUATASK_H_
#define LUATASK_H_

#include "serial.h"

#include <stddef.h>

void startLuaTask(int priority);

void* getLua(void);

void setAllocDebug(int enableDebug);
int getAllocDebug();

void set_ontick_freq(size_t freq);
size_t get_ontick_freq();

void initialize_lua();
void terminate_lua();
void run_lua_interactive_cmd(Serial *serial, const char* cmd);

#endif /*LUATASK_H_*/
