#pragma once

// Common
#define WM_CHANGE_DIRECTORY (WM_USER + 1)
#define WM_RESIZEPAGE (WM_USER + 2)
#define WM_UPDATE_CONTROLS (WM_USER + 3)
#define WM_SELECT_PROPERTYITEM (WM_USER + 4)
#define WM_CHANGE_PROPERTYITEM (WM_USER + 5)
#define WM_DBLCLK_PROPERTYITEM (WM_USER + 6)
#define WM_RCLK_PROPERTYITEM (WM_USER + 7)
#define WM_ACTIVATE_TOOL (WM_USER + 8)
#define WM_CLOSING_PANELS (WM_USER + 9)

// WorldEditor
#define WM_NEW_SPACE (WM_USER + 10)
#define WM_BEGIN_SAVE (WM_USER + 11)
#define WM_END_SAVE (WM_USER + 12)
#define WM_TERRAIN_TEXTURE_SELECTED (WM_USER + 13)
#define WM_TERRAIN_TEXTURE_RIGHT_CLICK (WM_USER + 14)
#define WM_CHANGED_CHUNK_STATE (WM_USER + 15)
#define WM_WORKING_CHUNK (WM_USER + 16)
#define WM_CHUNK_WATCH_MOUSE_MOVE (WM_USER + 17)
#define WM_DEFAULT_PANELS (WM_USER + 18)
#define WM_LAST_PANELS (WM_USER + 19)

// ParticleEditor
#define WM_DELETE_NODE (WM_USER + 20)
#define WM_DRAG_START (WM_USER + 21)
#define WM_DRAG_DONE (WM_USER + 22)
#define WM_PSTREE_CMENU (WM_USER + 23)

// Scene Browser
#define WM_LIST_GROUP_BY_CHANGED (WM_USER + 50)
#define WM_LIST_SCROLL_TO (WM_USER + 51)

// Post-Processing
#define WM_PP_ZOOM_IN (WM_USER + 52)
#define WM_PP_ZOOM_OUT (WM_USER + 53)
#define WM_PP_NO_ZOOM (WM_USER + 54)
#define WM_PP_3D_PREVIEW (WM_USER + 55)
#define WM_PP_PROFILE (WM_USER + 56)
#define WM_PP_LAYOUT (WM_USER + 57)
#define WM_PP_DELETE_ALL (WM_USER + 58)
#define WM_PP_CHAIN_SELECTED (WM_USER + 59)

// Property list
#define USER_RESERVED_CONTROL_ID 20000

#define IDC_PROPERTYLIST_STRING (USER_RESERVED_CONTROL_ID + 100)
#define IDC_PROPERTYLIST_COMBO (USER_RESERVED_CONTROL_ID + 101)
#define IDC_PROPERTYLIST_BOOL (USER_RESERVED_CONTROL_ID + 102)
#define IDC_PROPERTYLIST_LIST (USER_RESERVED_CONTROL_ID + 103)
#define IDC_PROPERTYLIST_TREE (USER_RESERVED_CONTROL_ID + 104)
#define IDC_PROPERTYLIST_FLOAT (USER_RESERVED_CONTROL_ID + 105)
#define IDC_PROPERTYLIST_INT (USER_RESERVED_CONTROL_ID + 106)
#define IDC_PROPERTYLIST_VECTOR3 (USER_RESERVED_CONTROL_ID + 107)
#define IDC_ERRORLIST_ITEM (USER_RESERVED_CONTROL_ID + 108)
#define IDC_PROPERTYLIST_BROWSE (USER_RESERVED_CONTROL_ID + 109)
#define IDC_PROPERTYLIST_DEFAULT (USER_RESERVED_CONTROL_ID + 110)
#define IDC_PROPERTYLIST_SLIDER (USER_RESERVED_CONTROL_ID + 111)
#define IDC_PROPERTYLIST_ARRAY_DEL (USER_RESERVED_CONTROL_ID + 112)
#define IDC_PROPERTYLIST_CUSTOM_MIN (USER_RESERVED_CONTROL_ID + 200)
#define IDC_PROPERTYLIST_CUSTOM_MAX (USER_RESERVED_CONTROL_ID + 299)
