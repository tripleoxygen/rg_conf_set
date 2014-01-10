/*
 * rg_conf_set - Sets configuration database parameters
 * Copyright (C) 2014  Triple Oxygen <oxy@g3n.org>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 * 
 */

#include <stdio.h>
#include "sgdbaccess.h"

#define VER "0.1"

void usage() {
	printf("Usage:\n");
	printf("\trg_conf_set <conf_path> <value>\n\n");
	printf("Example:\n");
	printf("\trg_conf_set Gvt/runlevel 4\n");
	printf("\trg_conf_set dev/ath0/wl_ap/wl_ssid \"pwned\"\n");
}

int main(int argc, char *argv[]) {
	SG_DB_Handle sgdb;
	int ret = 0;
	
	printf("rg_conf_set v%s\n", VER);
	printf("Copyright (C) 2014  Triple Oxygen <oxy@g3n.org>\n\n");
	
	if(argc != 3) {
		usage(argv[0]);
		return -1;
	}
	
	sgdb = SG_DB_Open(NULL);
	if(!sgdb) {
		printf("[-] Failed to open SG DB.");
		return -1;
	}
	
	ret = SG_DB_Set(sgdb, argv[1], argv[2]);
	printf("[+] Ret code: %d\n", ret);
	
	SG_DB_Close(sgdb);
	
	printf("[+] Done.\n\n");
	
	return 0;
}
