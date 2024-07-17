#ifndef ASTAL_RIVER_H
#define ASTAL_RIVER_H

#include <glib-object.h>

G_BEGIN_DECLS

#define ASTAL_RIVER_TYPE_OUTPUT (astal_river_output_get_type())

G_DECLARE_FINAL_TYPE(AstalRiverOutput, astal_river_output, ASTAL_RIVER, OUTPUT, GObject)

guint astal_river_output_get_id(AstalRiverOutput *self);

gchar *astal_river_output_get_name(AstalRiverOutput *self);

gchar *astal_river_output_get_layout_name(AstalRiverOutput *self);

gchar *astal_river_output_get_focused_view(AstalRiverOutput *self);

guint astal_river_output_get_focused_tags(AstalRiverOutput *self);

guint astal_river_output_get_urgent_tags(AstalRiverOutput *self);

guint astal_river_output_get_occupied_tags(AstalRiverOutput *self);

#define ASTAL_RIVER_TYPE_RIVER (astal_river_river_get_type())

G_DECLARE_FINAL_TYPE(AstalRiverRiver, astal_river_river, ASTAL_RIVER, RIVER, GObject)

AstalRiverRiver *astal_river_river_new();

AstalRiverRiver *astal_river_river_get_default();
AstalRiverRiver *astal_river_get_default();

GList *astal_river_river_get_outputs(AstalRiverRiver *self);

AstalRiverOutput *astal_river_river_get_output(AstalRiverRiver *self, gchar *name);

gchar *astal_river_river_get_focused_view(AstalRiverRiver *self);

gchar *astal_river_river_get_focused_output(AstalRiverRiver *self);

gchar *astal_river_river_get_mode(AstalRiverRiver *self);

/**
 * AstalRiverCommandCallback:
 * @success: a #gboolean indicating whether the command was executed successfully
 * @msg: a string containing the result of the command
 *
 * A callback function that is called after a river command is run.
 */
typedef void (*AstalRiverCommandCallback)(gboolean success, const gchar *msg);

void astal_river_river_run_command_async(AstalRiverRiver *self, gint length, const gchar **cmd,
                                         AstalRiverCommandCallback callback);

G_END_DECLS

#endif  // !ASTAL_RIVER_H
