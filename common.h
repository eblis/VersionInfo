/*
Version information plugin for Miranda IM

Copyright � 2002-2006 Luca Santarelli, Cristian Libotean

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
*/

#ifndef M_VERSIONINFO_COMMON_H
#define M_VERSIONINFO_COMMON_H

#pragma warning(disable:4005)
#define _CRT_SECURE_NO_DEPRECATE
#pragma warning(default:4005)

#define VIPF_NONE      0x0000
#define VIPF_UNCERTAIN 0x0010

#define VISF_FORUMSTYLE 0x0001
#define VISF_SHOWUUID   0x0002
#define VISF_SHOWFLAGS  0x0004

#include <windows.h>
#include <time.h>

#include <commctrl.h>
#include <list>
#include <imagehlp.h>
#include <winsock.h>

#include <String>
//using namespace std;

#include "version.h"

#include "m_versioninfo.h"
#include "hooked_events.h"
#include "services.h"
#include "dlgHandlers.h"

#include "../../include/newpluginapi.h"
#include "../../include/m_system.h"
#include "../../include/m_langpack.h"
#include "../../include/m_database.h"
#include "../../include/m_skin.h"
#include "../../include/m_clist.h"
#include "../../include/m_options.h"
#include "../../include/m_popup.h"

#include "../../include/m_utils.h"
#include "../../include/m_updater.h"
#include "../../include/m_folders.h"

#include "utils.h"

#ifndef MS_DB_GETPROFILEPATH_BASIC //db3xSA
#define MS_DB_GETPROFILEPATH_BASIC	"DB/GetProfilePathBasic"
#endif

//main.cpp
extern HINSTANCE hInst;

//main.cpp
extern HICON hiVIIcon;

//main.cpp
extern DWORD EnglishLocale;

//for folders support
extern BOOL bFoldersAvailable;
extern HANDLE hOutputLocation;

//services.cpp
extern int bServiceMode;

//main.cpp
extern char ModuleName[];
extern BOOL verbose;

#define DEFAULT_UPLOAD_PORT 51234

const MUUID UUID_NULL = {0x00000000, 0x0000, 0x0000, { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 }};

//miranda [re]alloc and free functions
//main.cpp
extern void * (* MirandaMalloc)(size_t);
extern void * (* MirandaRealloc)(void *, size_t);
extern void (* MirandaFree)(void *);

#define OLD_MIRANDAPLUGININFO_SUPPORT PLUGININFO oldPluginInfo = { \
	sizeof(PLUGININFO), \
	pluginInfo.shortName, \
	pluginInfo.version, \
	pluginInfo.description, \
	pluginInfo.author, \
	pluginInfo.authorEmail, \
	pluginInfo.copyright, \
	pluginInfo.homepage, \
	pluginInfo.flags, \
	pluginInfo.replacesDefaultModule \
}; \
\
extern "C" __declspec(dllexport) PLUGININFO *MirandaPluginInfo(DWORD mirandaVersion) \
{ \
	return &oldPluginInfo; \
}

#endif