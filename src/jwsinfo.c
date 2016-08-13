/* jwsinfo.h - header for JwsInfo class

Copyright (C) 2016 Jason Waataja

This file is part of JWS.

JWS is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

JWS is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with JWS.  If not, see <http://www.gnu.org/licenses/>.  */

#include "jwsinfo.h"

#include <glib.h>
#include <glib/gi18n.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct _JwsInfo
{
  GObject parent;
};

struct _JwsInfoClass
{
  GObjectClass parent_class;
};

typedef struct _JwsInfoPrivate JwsInfoPrivate;

struct _JwsInfoPrivate
{
  gboolean rotate_image;
  guint rotate_seconds;
  gboolean randomize_order;

  GList *file_list;
};

G_DEFINE_TYPE_WITH_PRIVATE (JwsInfo, jws_info, G_TYPE_OBJECT);

static void
jws_info_dispose (GObject *obj)
{
  JwsInfoPrivate *priv;
  priv = jws_info_get_instance_private (JWS_INFO (obj));

  G_OBJECT_CLASS (jws_info_parent_class)->dispose (obj);
}

static void
jws_info_finalize (GObject *obj)
{
  JwsInfoPrivate *priv;
  priv = jws_info_get_instance_private (JWS_INFO (obj));

  for (GList *iter = priv->file_list; iter != NULL; iter = g_list_next (iter))
    {
      g_free (iter->data);
      iter->data = NULL;
    }
  g_list_free (priv->file_list);
  priv->file_list = NULL;

  G_OBJECT_CLASS (jws_info_parent_class)->finalize (obj);
}

static void
jws_info_init (JwsInfo *self)
{
  JwsInfoPrivate *priv;
  priv = jws_info_get_instance_private (self);

  priv->rotate_image = TRUE;
  priv->rotate_seconds = 60;
  priv->randomize_order = TRUE;

  priv->file_list = NULL;
}

static void
jws_info_class_init (JwsInfoClass *kclass)
{
  GObjectClass *as_object_class;
  as_object_class = G_OBJECT_CLASS (kclass);

  as_object_class->dispose = jws_info_dispose;
  as_object_class->finalize = jws_info_finalize;
}


JwsInfo *
jws_info_new ()
{
  return g_object_new (JWS_TYPE_INFO, NULL);
}

JwsInfo *
jws_info_new_from_file (const gchar *path)
{
  JwsInfo *obj;
  obj = jws_info_new ();
  jws_info_set_from_file (obj, path);
  return obj;
}

gboolean
jws_info_get_rotate_image (JwsInfo *info)
{
  if (info)
    {
      JwsInfoPrivate *priv;
      priv = jws_info_get_instance_private (info);
      return priv->rotate_image;
    }
  else
    {
      return FALSE;
    }
}

void
jws_info_set_rotate_image (JwsInfo *info, gboolean rotate_image)
{
  if (info)
    {
      JwsInfoPrivate *priv;
      priv = jws_info_get_instance_private (info);
      priv->rotate_image = rotate_image;
    }
}

guint
jws_info_get_rotate_seconds (JwsInfo *info)
{
  if (info)
    {
      JwsInfoPrivate *priv;
      priv = jws_info_get_instance_private (info);
      return priv->rotate_seconds;
    }
  else
    {
      return 0;
    }
}

void
jws_info_set_rotate_seconds (JwsInfo *info, guint rotate_seconds)
{
  if (info)
    {
      JwsInfoPrivate *priv;
      priv = jws_info_get_instance_private (info);
      priv->rotate_seconds = rotate_seconds;
    }
}

gboolean
jws_info_get_randomize_order (JwsInfo *info)
{
  if (info)
    {
      JwsInfoPrivate *priv;
      priv = jws_info_get_instance_private (info);
      return priv->randomize_order;
    }
  else
    {
      return FALSE;
    }
}

void
jws_info_set_randomize_order (JwsInfo *info, gboolean randomize_order)
{
  if (info)
    {
      JwsInfoPrivate *priv;
      priv = jws_info_get_instance_private (info);
      priv->randomize_order = randomize_order;
    }
}


GList *
jws_info_get_file_list (JwsInfo *info)
{
  if (info)
    {
      JwsInfoPrivate *priv;
      priv = jws_info_get_instance_private (info);
      return priv->file_list;
    }
  else
    {
      return NULL;
    }
}

void
jws_info_set_file_list (JwsInfo *info, GList *file_list)
{
  if (info)
    {
      JwsInfoPrivate *priv;
      priv = jws_info_get_instance_private (info);

      for (GList *iter = priv->file_list; iter != NULL; iter = g_list_next (iter))
        {
          g_free (iter->data);
          iter->data = NULL;
        }
      g_list_free (priv->file_list);

      priv->file_list = file_list;
    }
}

void
jws_info_add_file (JwsInfo *info, const gchar *path)
{
  if (info)
    {
      JwsInfoPrivate *priv;
      priv = jws_info_get_instance_private (info);

      priv->file_list = g_list_append (priv->file_list, g_strdup (path));
    }
}

void
jws_info_remove_file (JwsInfo *info, const gchar *path)
{
  if (info)
    {
      JwsInfoPrivate *priv;
      priv = jws_info_get_instance_private (info);

      gboolean found_item;
      for (GList *iter = priv->file_list; iter != NULL && !found_item;
           iter = g_list_next (iter))
        {
          gchar *iter_path;
          iter_path = iter->data;
          if (g_str_equal (iter_path, path))
            {
              priv->file_list = g_list_remove (priv->file_list, iter_path);
              found_item = TRUE;
            }
        }
    }
}

gboolean
jws_info_set_from_file (JwsInfo *info, const gchar *path)
{
  if (info)
    {
      JwsInfoPrivate *priv;
      priv = jws_info_get_instance_private (info);

      GList *line_list = NULL;

      GIOChannel *channel;
      channel = g_io_channel_new_file (path, "r", NULL);

      if (!channel)
        return FALSE;

      gchar *line = NULL;;
      gsize line_length;
      gsize terminator_pos;

      GIOStatus status;
      status = g_io_channel_read_line (channel, &line, &line_length,
                                       &terminator_pos, NULL);

      while (status == G_IO_STATUS_NORMAL)
        {
          if (line && terminator_pos)
            line[terminator_pos] = '\0';

          line_list = g_list_append (line_list, g_strdup (line));
          g_free (line);
          line = NULL;

          status = g_io_channel_read_line (channel, &line, &line_length,
                                           &terminator_pos, NULL);
        }
      g_free (line);
      line = NULL;

      g_io_channel_shutdown (channel, FALSE, NULL);
      g_io_channel_unref (channel);

      gboolean has_files = FALSE;

      GList *iter;

      for (iter = line_list;
           iter != NULL && !has_files;
           iter = g_list_next (iter))
        {
          line = iter->data;

          if (g_str_has_prefix (line, "files"))
            {
              has_files = TRUE;
            }
          else if (g_str_has_prefix (line, "rotate-image"))
            {
              priv->rotate_image = TRUE;
            }
          else if (g_str_has_prefix (line, "single-image"))
            {
              priv->rotate_image = FALSE;
            }
          else if (g_str_has_prefix (line, "time"))
            {
              gchar **tokens;
              tokens = g_strsplit_set (line, " \t\n", -1);

              if (tokens[1] == NULL)
                {
                  g_printerr (_("No argument provided for \"time\"\n"));
                }
              else
                {
                  int as_int = atoi (tokens[1]);
                  priv->rotate_seconds = MAX (as_int, 1);
                }
              g_strfreev (tokens);
            }
          else if (g_str_has_prefix (line, "rotate-image"))
            {
              priv->randomize_order = TRUE;
            }
          else if (g_str_has_prefix (line, "in-order"))
            {
              priv->randomize_order = FALSE;
            }
        }

      if (!has_files)
        {
          return FALSE;
        }

      for (; iter != NULL; iter = g_list_next (iter))
        {
          line = iter->data;

          if (strlen (line) > 0)
            {
              jws_info_add_file (info, line);
            }
        }
      for (iter = line_list; iter != NULL; iter = g_list_next (iter))
        {
          iter->data = NULL;
        }
      g_list_free (line_list);
      return TRUE;
    }
  else
    {
      return FALSE;
    }
}

gboolean
jws_info_write_to_file (JwsInfo *info, const gchar *path)
{
  JwsInfoPrivate *priv;
  priv = jws_info_get_instance_private (info);
  
  GIOChannel *writer;
  writer = g_io_channel_new_file (path, "w", NULL);

  if (!writer)
    return FALSE;

  gboolean status;

  if (priv->rotate_image)
    {
      status = jws_write_line (writer, "rotate-image");
      if (!status)
        {
          g_io_channel_shutdown (writer, TRUE, NULL);
          g_io_channel_unref (writer);
          return FALSE;
        }

      if (priv->randomize_order)
        {
          status = jws_write_line (writer, "randomize-order");
          if (!status)
            {
              g_io_channel_shutdown (writer, TRUE, NULL);
              g_io_channel_unref (writer);
              return FALSE;
            }
        }
      else
        {
          status = jws_write_line (writer, "in-order");
          if (!status)
            {
              g_io_channel_shutdown (writer, TRUE, NULL);
              g_io_channel_unref (writer);
              return FALSE;
            }
        }
      size_t buf_size = 80;
      char buf[buf_size];
      int bytes_written;
      bytes_written = snprintf (buf, 80, "%i", priv->rotate_seconds);

      if (bytes_written <= 0 && bytes_written >= buf_size)
        {
          g_io_channel_shutdown (writer, TRUE, NULL);
          g_io_channel_unref (writer);
          return FALSE;
        }

      gchar *time_line;
      time_line = g_strconcat ("time ", buf, NULL);

      status = jws_write_line (writer, time_line);
      if (!status)
        {
          g_io_channel_shutdown (writer, TRUE, NULL);
          g_io_channel_unref (writer);
          return FALSE;
        }
    }
  else
    {
      status = jws_write_line (writer, "single-image");
      if (!status)
        {
          g_io_channel_shutdown (writer, TRUE, NULL);
          g_io_channel_unref (writer);
          return FALSE;
        }
    }

  status = jws_write_line (writer, "");
  if (!status)
    {
      g_io_channel_shutdown (writer, TRUE, NULL);
      g_io_channel_unref (writer);
      return FALSE;
    }
  status = jws_write_line (writer, "files");
  if (!status)
    {
      g_io_channel_shutdown (writer, TRUE, NULL);
      g_io_channel_unref (writer);
      return FALSE;
    }
  GList *iter;
  for (iter = g_list_first (priv->file_list); iter; iter = g_list_next (iter))
    {
      status = jws_write_line (writer, iter->data);
      if (!status)
        {
          g_io_channel_shutdown (writer, TRUE, NULL);
          g_io_channel_unref (writer);
          return FALSE;
        }
    }
  g_io_channel_shutdown (writer, TRUE, NULL);
  g_io_channel_unref (writer);
  return TRUE;
}

void
print_jws_info (JwsInfo *info)
{
  if (info)
    {
      JwsInfoPrivate *priv;
      priv = jws_info_get_instance_private (info);

      if (priv->rotate_image)
        {
          g_print (_("Rotate image\n"));
          
          g_print (_("Seconds between rotation: %i\n"), priv->rotate_seconds);

          if (priv->randomize_order)
            g_print (_("Randomize order\n"));
          else
            g_print (_("In order"));

        }
      else
        {
          g_print (_("Single image\n"));
        }

      GList *file_list = priv->file_list;

      if (file_list)
        {
          g_print (_("Files:\n"));

          for (; file_list != NULL; file_list = g_list_next (file_list))
            {
              g_print ("%s\n", file_list->data);
            }
        }
      else
        {
          g_print (_("No files to print\n"));
        }
    }
  else
    {
      g_print (_("Error: Trying to print null info\n"));
    }
}

gboolean
jws_write_line (GIOChannel *channel, const gchar *message)
{
  gchar *new_message;
  new_message = g_strconcat (message, "\n", NULL);

  GIOStatus status;
  gsize size;
  status = g_io_channel_write_chars (channel,
                                     new_message,
                                     -1,
                                     &size,
                                     NULL);
  g_free (new_message);
  return (status == G_IO_STATUS_NORMAL);
}
