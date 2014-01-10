#
# rg_conf_set - Sets configuration database parameters
# Copyright (C) 2014  Triple Oxygen <oxy@g3n.org>
#
# This program is free software; you can redistribute it and/or
# modify it under the terms of the GNU General Public License
# as published by the Free Software Foundation; either version 2
# of the License, or (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program; if not, write to the Free Software
# Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
#

CC=~/embedded/mips-linux-uclibc/bin/mips-linux-gcc
CFLAGS=-c -Wall
LDFLAGS=-L../../image/8388/fs/lib -lsgdbaccess -ljutil -lopenrg_gpl

all: rg_conf_set

rg_conf_set: rg_conf_set.o
	$(CC) $(LDFLAGS) -o rg_conf_set rg_conf_set.o

rg_conf_set.o: rg_conf_set.c
	$(CC) $(CFLAGS) rg_conf_set.c

clean:
	rm -rf *.o rg_conf_set	
