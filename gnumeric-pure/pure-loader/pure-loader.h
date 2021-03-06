#ifndef GNM_PURE_PLUGIN_LOADER_H
#define GNM_PURE_PLUGIN_LOADER_H

#include <gnumeric-features.h>

#if GNM_VERSION_EPOCH <= 1 && GNM_VERSION_MAJOR <= 9 && GNM_VERSION_MINOR < 12
#define OLD_API
#ifndef GNM_VERSION_FULL
#ifdef GNM_VERSION
#define GNM_VERSION_FULL GNM_VERSION
#else
#define GNM_VERSION_FULL "<unknown>"
#endif
#endif
#endif

#include <glib-object.h>
#include <pure/runtime.h>
#include "pure-gnumeric.h"

#define GETTEXT_PACKAGE "gnumeric"

#ifdef OLD_API
#define GO_TYPE_PLUGIN_LOADER GO_PLUGIN_LOADER_TYPE
#define GOErrorInfo ErrorInfo
#define go_plugin_service_get_cbs plugin_service_get_cbs
#define go_error_info_new_str error_info_new_str
#define go_error_info_new_printf error_info_new_printf
#endif

#ifndef PLUGIN_VERSION
#define PLUGIN_VERSION "0.0"
#endif

GType gnm_pure_plugin_loader_get_type (void);
void  gnm_pure_plugin_loader_register_type (GTypeModule *module);
void  pure_stop(GnmAction const *action, WorkbookControl *wbc);
void  pure_reload(GnmAction const *action, WorkbookControl *wbc);
void  pure_edit(GnmAction const *action, WorkbookControl *wbc);

/* asynchronous function interface */

extern char *pure_async_filename;
gboolean pure_async_func_init(const GnmFuncEvalInfo *ei, pure_expr *ex,
			      unsigned id, pure_expr **x);
void pure_async_func_process(const GnmFuncEvalInfo *ei, unsigned id, int pid);
void pure_async_func_stop(const GnmFuncEvalInfo *ei, unsigned id);
void pure_async_set_value(const GnmFuncEvalInfo *ei, unsigned id, pure_expr *x);

/* GL window interface */

GLWindow *pure_get_gl_window(const DepKey *key);
void pure_add_gl_window(const DepKey *key, GLWindow *glw);
void pure_remove_gl_window(const DepKey *key);

#endif /* GNM_PURE_PLUGIN_LOADER_H */
