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

#ifndef _SGDBACCESS_H_
#define _SGDBACCESS_H_

#define SG_DB_Handle void *

extern SG_DB_Handle SG_DB_Open(SG_DB_Handle prev);
extern void  SG_DB_Close(SG_DB_Handle h);
extern void  SG_DB_Close_Reconf(SG_DB_Handle h, int u);

extern char	*SG_DB_Get(SG_DB_Handle sgdb, char *path);
extern int	SG_DB_Set(SG_DB_Handle sgdb, char *path, char *data);

/* untested */
extern void SG_DB_Get_Int(SG_DB_Handle sgdb, char *path, int *i);
extern int	SG_DB_Close_ThreadSafe(SG_DB_Handle sgdb, int unk);
extern char *SG_DB_Get(SG_DB_Handle sgdb, char *path);
extern void SG_DB_Delete(SG_DB_Handle sgdb, char *path);

#endif
