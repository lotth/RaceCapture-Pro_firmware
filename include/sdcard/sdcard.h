/*
 * Race Capture Firmware
 *
 * Copyright (C) 2016 Autosport Labs
 *
 * This file is part of the Race Capture firmware suite
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

#ifndef SDCARD_H_
#define SDCARD_H_

#include "cpp_guard.h"
#include "serial.h"
#include "ff.h"
#include "sampleRecord.h"

CPP_GUARD_BEGIN

#define SD_EXTRA_STACK 128

FRESULT sd_open( FIL* file, const TCHAR* path, BYTE mode );
FRESULT sd_close( FIL* file );
FRESULT sd_write( FIL* file, const void* buf, UINT btr, UINT* br );
FRESULT sd_read( FIL* file, void* buff, UINT btr, UINT* br );
FRESULT sd_lseek( FIL* file, DWORD ofs );
FRESULT sd_sync( FIL* file );
FRESULT sd_truncate( FIL* file );

TCHAR*  sd_gets( TCHAR* buff, int len, FIL* fp );
DWORD   sd_size( FIL* file );
int	sd_puts (const TCHAR* str, FIL* cp);	

bool test_sd(struct Serial *serial, int lines,int doFlush, int quiet);
void test_sd_interactive(struct Serial *serial, int lines,int doFlush, int quiet);
void InitFSHardware(void);
int InitFS(); // Why doesn't this return FRESULT?
int UnmountFS(); // Why doesn't this return FRESULT?
// check the sdcard to see if its ready
// remount the filesystem if necessary.
bool sdcard_write_ready( const bool no_delay );
bool sdcard_ready( const bool no_delay );
bool sdcard_present();
bool sdcard_open_next(FIL* fp, char* name_buf, const char* base, const char* ext, const uint32_t maxIdx );
bool sdcard_fs_mounted(void);
int OpenNextLogFile(FIL *f);
bool fs_lock(void);
void fs_unlock(void);
void fs_write_sample_record(FIL *buffer_file,
                            const struct sample *sample,
                            const unsigned int tick, const int sendMeta);

CPP_GUARD_END

#endif /*SDCARD_H_*/
